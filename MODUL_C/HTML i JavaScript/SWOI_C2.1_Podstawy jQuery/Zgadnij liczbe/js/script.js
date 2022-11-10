$(function(){
  var _liczba,
      liczbaProb = 0;

  var losuj = function(min, max) {
    _liczba = Math.floor(Math.random()*(max-min))+min;
  };

  losuj(1, 100);

  $('section').on('click', '#reset', function(event){
    losuj(1, 100);
    $('#odpowiedz').replaceWith($('<ul>').attr('id', 'odpowiedz'));
  });

  $('#zgaduj').on('click', function(event){
    var msg = '',
        strzal = parseInt($('#strzal').val(), 10);

    liczbaProb++;

    msg = 'Twoja liczba to: ' + strzal + '.';

    if (strzal < _liczba) msg += ' Szukana liczba jest większa od podanej.';
    if (strzal > _liczba) msg += ' Szukana liczba jest mniejsza od podanej.';
    if (strzal === _liczba) {
      msg += ' Gratulacej jest to poprawna liczba!';
      msg += ' Zgadłeś po ' + liczbaProb + ' próbach.';
    }
    $('#odpowiedz').append($('<li>').text(msg));
    if (strzal === _liczba) {
      $('#odpowiedz').append($('<li>').html('<input id="reset" type="submit" value="Zagraj ponownie">'));
    }
    $('#strzal').val('').focus();
    return false;
  });
});