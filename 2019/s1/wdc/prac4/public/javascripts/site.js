
var xhttp = new XMLHttpRequest();

function getContact() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
			document.getElementById("addContent").innerHTML = this.responseText;
		}
	};

	xhttp.open("GET","/contact.ajax",true);

	xhttp.send();

}

function getSearch() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
			document.getElementById("addContent").innerHTML = this.responseText;
		}
	};

	xhttp.open("GET","/search.ajax",true);

	xhttp.send();

}

function getAbout() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
			document.getElementById("addContent").innerHTML = this.responseText;
		}
	};

	xhttp.open("GET","/about.ajax",true);

	xhttp.send();

}
