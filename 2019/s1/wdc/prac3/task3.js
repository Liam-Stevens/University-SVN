var inc = 0;
var count = document.createElement("P");

var addDate = document.createElement("P");
var addContent = document.createElement("P");
addDate.className += "post-time";
addContent.className += "post-content";

function myFunction() {
	count.innerHTML = inc;
	document.getElementById("mcount").appendChild(count);
	inc++;
	count.innerHTML = inc;
}

function createPost() {
	var date = new Date();
	addDate.innerHTML = date;
	addContent.innerHTML = document.getElementById("content-area").value; 
	document.getElementById("posts").appendChild(addDate);
	document.getElementById("posts").appendChild(addContent);
}