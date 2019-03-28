var inc = 0;
var count = document.createElement("P");
var postNum = 0;

function myFunction() {
	count.innerHTML = inc;
	document.getElementById("mcount").appendChild(count);
	inc++;
	count.innerHTML = inc;
}

function createPost() {
	for(var i = 0; i < document.getElementById("numButton").value; i++) {
		postNum++;
		var addDate = document.createElement("P");
		var addContent = document.createElement("P");
		addDate.className += "post-time";
		addContent.className += "post-content";
		var date = new Date();
		addDate.innerHTML = date;
		addContent.innerHTML = document.getElementById("content-area").value; 
		if(document.getElementById("redButton").checked) {
			addContent.style.color = "Red";
		}
		if(document.getElementById("blueButton").checked) {
			addContent.style.color = "Blue";
		}
		if(document.getElementById("boldBox").checked) {
			addContent.innerHTML = addContent.innerHTML.bold();
		}
		if(document.getElementById("italBox").checked) {
			addContent.innerHTML = addContent.innerHTML.italics();
		}
		document.getElementById("posts").appendChild(addDate);
		document.getElementById("posts").appendChild(addContent);
	}
}

function toggleMain() {
	if (document.getElementById("main").style.display === "none") {
    document.getElementById("main").style.display = "block";
    document.getElementById("menu").style.display = "none";
  } else {
    document.getElementById("main").style.display = "none";
    document.getElementById("menu").style.display = "block";
  }
}

function changeBackground() {
	document.body.style.backgroundColor = document.getElementById("backgroundBox").value;
}


