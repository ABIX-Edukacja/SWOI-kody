$(function(){
  var db,
      request = indexedDB.open('ToDo', 2);

  request.onerror = function(event) {
    alert('Wystąpił błąd. Nie można otworzyć bazy danych.');
  };

  request.onupgradeneeded = function(event) {
    console.log('Tasks object store initialized.');
    request.result.createObjectStore('tasks', {keyPath: 'timestamp', autoIncrement: true});
  };

  request.onsuccess = function(event) {

    db = request.result;
    var trans = db.transaction(['tasks']),
        store = trans.objectStore('tasks');

    var cursorRequest = store.openCursor();

    $wrapper = $('<ul>');

    cursorRequest.onsuccess = function(event) {
      var result = event.target.result,
          $li = $('<li>'),
          i;

      if(!!result === false) {
        $('#all-tasks').html($wrapper.html());
        return;
      }

      delete result.value.timestamp;

      for (i in result.value) {
        $li.append(
          $('<span>').addClass(i).html(result.value[i])
        );
      }
      $wrapper.append($li);
      console.log($wrapper.html());
      result.continue();
    };

  };



  $('form').on('submit', function(event){
    event.preventDefault();

    var trans = db.transaction(['tasks'], 'readwrite'),
        store = trans.objectStore('tasks'),
        $this = $(this),
        data = $this.serializeArray(),
        i = 0,
        l = data.length,
        zadanie = {};

    for (i = 0, l = data.length; i < l; ++i) {
      zadanie[data[i].name] = data[i].value;
    }
    zadanie.timestamp = new Date().getTime();
    store.put(zadanie);
    return false;
  });

});