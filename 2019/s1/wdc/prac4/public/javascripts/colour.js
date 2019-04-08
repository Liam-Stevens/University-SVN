var xhttp = new XMLHttpRequest();

function getColour() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
			document.getElementById("headColour").innerHTML = this.responseText;
			document.getElementById("headColour").style.color = this.responseText;
		}
	};

	xhttp.open("GET","/colour.txt",true);

	xhttp.send();

}