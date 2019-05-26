var xhttp = new XMLHttpRequest();

function makePost() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
			//Do stuff if successful
		}
	};

	xhttp.open("POST","/users/addpost",true);
    xhttp.setRequestHeader("Content-type", "application/json");
	xhttp.send(JSON.stringify({ title:document.getElementById('title').value, content:document.getElementById('content').value }));

}
