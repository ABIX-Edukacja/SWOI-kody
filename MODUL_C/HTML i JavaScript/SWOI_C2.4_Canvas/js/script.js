document.addEventListener('DOMContentLoaded', function(){
  var canvas = document.getElementById('canvas');
  var ctx = canvas.getContext('2d');
  var objects = [];

  var drawDemo = function() {
    ctx.save();

    ctx.fillStyle = "rgb(0,200,0)";

    ctx.beginPath();
    ctx.moveTo(200,200);
    ctx.lineTo(250,250);
    ctx.lineTo(250,300);
    ctx.lineTo(200,350);
    ctx.lineTo(150,300);
    ctx.lineTo(150,250);
    ctx.closePath();
    ctx.fill();

    ctx.fillStyle = "rgb(200,0,0)";
    ctx.fillRect(10, 10, 100, 100);

    ctx.strokeRect(200, 10, 100, 100);

    ctx.restore();
  };



  var startX, startY, drawing = false;

  canvas.addEventListener('mousedown', function(event) {
    startX = event.layerX;
    startY = event.layerY;
    drawing = true;
  });

  canvas.addEventListener('mouseup', function(event) {
    drawing = false;
    ctx.fillRect(startX, startY, event.layerX - startX, event.layerY - startY);
    objects.push({
      x: startX,
      y: startY,
      width: (event.layerX - startX),
      height: (event.layerY - startY),
      color: ctx.fillStyle
    });
    console.log(objects[objects.length -1]);
  });

  canvas.addEventListener('mousemove', function(event){
    if (drawing) {
      var i = 0, l = objects.length;

      ctx.save();

      ctx.clearRect(0,0,700,500);

      for (i = 0; i < l; i++) {
        ctx.fillStyle = objects[i].color;
        ctx.fillRect(objects[i].x, objects[i].y, objects[i].width, objects[i].height);
      }
      ctx.restore();

      ctx.strokeRect(startX, startY, event.layerX - startX, event.layerY - startY);
    }
  });

  var requestAnimationFrame = window.requestAnimationFrame ||
        window.mozRequestAnimationFrame ||
        window.webkitRequestAnimationFrame ||
        window.msRequestAnimationFrame;

  var fall  = function() {
    var i = 0, l = objects.length;
    if (!drawing) {
      ctx.clearRect(0,0,700,500);

      ctx.save();
      for (i = 0; i < l; i++) {
        if (objects[i].y + Math.max(0, objects[i].height) < 500 ) {
          objects[i].y += 10;
        }
        ctx.fillStyle = objects[i].color;
        ctx.fillRect(objects[i].x, objects[i].y, objects[i].width, objects[i].height);
      }
      ctx.restore();
    }
    requestAnimationFrame(fall);
  };
  requestAnimationFrame(fall);
});