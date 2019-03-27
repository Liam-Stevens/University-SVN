var inc = 0;
var count = document.createElement("P");

window.onload = function() {
	count.innerHTML = inc;
	document.getElementById("mcount").appendChild(count);
};

function myFunction() {
	inc++;
	count.innerHTML = inc;
}