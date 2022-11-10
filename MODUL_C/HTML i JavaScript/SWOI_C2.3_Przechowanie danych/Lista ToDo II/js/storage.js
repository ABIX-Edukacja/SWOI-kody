$(function(){

  var listaZadan = localStorage.getItem('lista-zadan') || JSON.stringify([]);
  listaZadan = JSON.parse(listaZadan);

  $wrapper = $('<ul>');
  $.each(listaZadan, function(index,  elem) {
    var $li = $('<li>'),
        i;

    for (i in elem) {
      $li.append(
        $('<span>').addClass(i).html(elem[i])
      );
    }
    console.log(elem);
    $wrapper.append($li);
  });
  $('#all-tasks').html($wrapper.html());


  $('form').on('submit', function(event){
    event.preventDefault();

    var $this = $(this),
        data = $this.serializeArray(),
        i = 0,
        l = data.length,
        noweZadanie = {};

    for (i = 0, l = data.length; i < l; ++i) {
      noweZadanie[data[i].name] = data[i].value;
    }
    listaZadan.push(noweZadanie);
    localStorage.setItem('lista-zadan', JSON.stringify(listaZadan));

    return false;
  });

});