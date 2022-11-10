$(function(){

  $('#priorytet').on('change', function(event) {
    var $this = $(this),
        color = 'black';

    if ($this.val() === 'Wysoki') color = 'red';

    if ($this.val() === 'Niski') color = 'green';

    $this.parent().find('label').css('color', color);
  });

  $('#przypomnij').on('change', function(event) {
    var $this = $(this),
        $target = $this.parent().next();

    if ( $this.attr('checked') ) {
      // Pokaż bez animacji:
      $target.show();
      // Pokaż z animacja:
      // $target.fadeIn('slow');
    } else {
      // Ukryj bez animacji:
      $target.hide();
      // Ukryj z animacja:
      // $target.fadeOut('slow');
    }
  });

  $('#przypomnij').trigger('change');

  $('#termin').on('focus', function(event) {
    var $this = $(this);

    if ( $this.val() === '' ) {
      $this.val( new Date().toLocaleFormat('%d-%m-%Y') );
    }

  });

  $('#termin').on('keyup', function(event){
    var $this = $(this);

    if ( $this.val().match(/^[0-9]{1,2}\-[0-9]{1,2}\-[0-9]{4}$/) ) {
      $this.css('background-color', 'rgba(0,255,0,0.7)');
    } else {
      $this.css('background-color', 'rgba(255,0,0,0.7)');
    }
  });

  $('form').on('submit', function(event){
    event.preventDefault();

    var $this = $(this),
        data = $this.serializeArray(),
        $li = $('<li>'),
        $target = $('#all-tasks'),
        i, l;

    for (i = 0, l = data.length; i < l; ++i) {
      $li.append(
        $('<span>').addClass(data[i].name).text(data[i].value)
      );
    }
    // Ddodaj bez animacji:
    $target.append($li);

    // Dodaj z animacja:
    // $target.append($li.hide());
    // $li.slideDown('slow');

    return false;
  });

  $('#all-tasks').on('click', 'li', function(event) {
    var $this = $(this);
    $this.toggleClass('done');
  });

});