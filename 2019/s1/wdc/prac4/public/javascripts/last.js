var xhttp = new XMLHttpRequest();

function getPara() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
			document.getElementById("lastUpdate").innerHTML = "This page was last viewed "+this.responseText;
		}
	};

	xhttp.open("GET","/last.txt",true);

	xhttp.send();

}