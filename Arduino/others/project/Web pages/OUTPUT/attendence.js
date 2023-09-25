function validate() {
    var x = document.forms["myForm"]["roll"].value;
	var y = document.forms["myForm"]["dept"].value;
	var z = document.forms["myForm"]["year"].value;
    if (x == "" ||y == "" ||z == "") {
        alert("Name must be filled out");
        return false;
    }
}