const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<HEAD>
<TITLE>ESP8266 With web server </TITLE>
</HEAD>
<style>
body{
  background-color: coral;
}
.card{
max-width: 400px;
min-height: 250px;
background: #ffffff;
padding: 30px;
box-sizing: border-box;
color: #000;
margin:20px;
box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>

<center>
<b>:)</b>

<div class="card">
<h4>Esp8266 web server calculating sensor value</h4><br>
<h1>Sensor Value:<span id="ldrValue">0</span></h1><br>
</div>
<script>

setInterval(function() {
// Call a function repetatively with 2 Second interval
getData();
}, 2000); //Seconds update rate

function getData() {
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
if (this.readyState == 4 && this.status == 200) {
document.getElementById("ldrValue").innerHTML =
this.responseText;
}
};
xhttp.open("GET", "readLDR", true);
xhttp.send();
}
</script>
</center>
</body>
</html>
)=====";