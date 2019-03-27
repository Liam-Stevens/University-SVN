var inc = 0;
var count = document.createElement("P");

function myFunction() {
	count.innerHTML = inc;
	document.getElementById("mcount").appendChild(count);
	inc++;
	count.innerHTML = inc;
}