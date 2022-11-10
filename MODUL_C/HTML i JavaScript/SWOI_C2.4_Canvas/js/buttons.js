document.addEventListener('DOMContentLoaded', function(){
  var canvas = document.getElementById('canvas');
  var ctx = canvas.getContext('2d');

  document.getElementById('red').addEventListener('click', function(event){
    event.preventDefault();
    ctx.fillStyle = "rgb(200,0,0)";
    ctx.strokeStyle = "rgb(200,0,0)";
    return false;
  });
  document.getElementById('green').addEventListener('click', function(event){
    event.preventDefault();
    ctx.fillStyle = "rgb(0,200,0)";
    ctx.strokeStyle = "rgb(0,200,0)";
    return false;
  });
  document.getElementById('blue').addEventListener('click', function(event){
    event.preventDefault();
    ctx.fillStyle = "rgb(0,0,200)";
    ctx.strokeStyle = "rgb(0,0,200)";
    return false;
  });
  document.getElementById('black').addEventListener('click', function(event){
    event.preventDefault();
    ctx.fillStyle = "rgb(0,0,0)";
    ctx.strokeStyle = "rgb(0,0,0)";
    return false;
  });
});