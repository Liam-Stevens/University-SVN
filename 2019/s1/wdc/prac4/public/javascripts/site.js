var xhttp = new XMLHttpRequest();

function getContact() {

	xhttp.onreadystatechange = function() {
		if (xhttp1.readyState == 4 && xhttp1.status == 200)
		{
			document.getElementById("addContent").innerHTML = this.responseText;
		}
	};

	xhttp1.open("GET","/contact.ajax",true);

	xhttp1.send();

}

function getSearch() {

	xhttp.onreadystatechange = function() {
		if (xhttp2.readyState == 4 && xhttp2.status == 200)
		{
			document.getElementById("addContent").innerHTML = this.responseText;
		}
	};

	xhttp2.open("GET","/search.ajax",true);

	xhttp2.send();

}

function getAbout() {

	xhttp.onreadystatechange = function() {
		if (xhttp3.readyState == 4 && xhttp3.status == 200)
		{
			document.getElementById("addContent").innerHTML = this.responseText;
		}
	};

	xhttp3.open("GET","/about.ajax",true);

	xhttp3.send();

}