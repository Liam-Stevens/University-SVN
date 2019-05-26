var xhttp = new XMLHttpRequest();

function getPost() {

	xhttp.onreadystatechange = function() {
		if (xhttp.readyState == 4 && xhttp.status == 200)
		{
            var postDetails = JSON.parse(this.response);
            console.log(postDetails);

            for (var i = 0; i < postDetails.length; i++){
                var addDiv = document.createElement("DIV");
                var addTitle = document.createElement("H2");
                var addContent = document.createElement("P");
                addTitle.innerHTML = postDetails[i].title;
                addContent.innerHTML = postDetails[i].content;
                addDiv.appendChild(addTitle);
                addDiv.appendChild(addContent);
                document.getElementById("posts").appendChild(addDiv);
            }
		}
	};

	xhttp.open("GET","/users/getposts",true);

	xhttp.send();

}
