<?php
// This displayes the selected row from the previous page
$colname_Member_info = "-1";
if (isset($_GET['recordID'])) {
$colname_Member_info = $_GET['recordID'];
}
mysql_select_db(strato11_members);
$query_Member_info = sprintf("SELECT * FROM Member_info WHERE id = %s", GetSQLValueString($colname_Member_info, 
"text"));
$Member_info = mysql_query($query_Member_info) or die(mysql_error());
$row_Member_info = mysql_fetch_assoc($Member_info);
$totalRows_Member_info = mysql_num_rows($Member_info);

// Form1 starts here to update the selected record
$editFormAction = $_SERVER['PHP_SELF'];
if (isset($_SERVER['QUERY_STRING'])) {
$editFormAction .= "?" . htmlentities($_SERVER['QUERY_STRING']);
}

// added by Jim to set image formats

     function GetImageExtension($imagetype) {
        if(empty($imagetype)) return false;
        switch($imagetype) {
            case 'image/bmp': return '.bmp';
            case 'image/gif': return '.gif';
            case 'image/jpeg': return '.jpg';
            case 'image/png': return '.png';
            default: return false;
        }
    } 

// added by JK to process image1
$target = "uploads/"; 
    if (isset($_FILES["image1"]["tmp_name"]) && !empty($_FILES["image1"]["tmp_name"])) {
        $temp_name=$_FILES["image1"]["tmp_name"];
        $imgtype=$_FILES["image1"]["type"];
        $ext= GetImageExtension($imgtype);

//This is the directory where images will be saved 
        if (!$ext) die("Upload file format is not allowed");
        $target1 = $target . basename( $_FILES['image1']['name']);
        if(move_uploaded_file($temp_name, $target1)) {
        } else {
            exit("Error While uploading image on the server"); 
        }
    }

// JK code ends

if ((isset($_POST["MM_update"])) && ($_POST["MM_update"] == "form1")) {
$updateSQL = sprintf("UPDATE `Member_info` SET name=%s, rank=%s, departed=%s, service=%, lodd=%s, veteran=%s, 
branch=%s, decorated=%s, comments=%s, image1=%, cemetery=%s WHERE id=%s",                
                   GetSQLValueString($_POST['name'], "text"),
                   GetSQLValueString($_POST['rank'], "text"),
                   GetSQLValueString($_POST['departed'], "text"),
                   GetSQLValueString($_POST['service'], "text"),
                   GetSQLValueString($_POST['lodd'], "text"),
                   GetSQLValueString($_POST['veteran'], "text"),
                   GetSQLValueString($_POST['branch'], "text"),
                   GetSQLValueString($_POST['decorated'], "text"),
                   GetSQLValueString($_POST['comments'], "text"),
                   GetSQLValueString($_POST['cemetery'], "text"),
                   GetSQLValueString($target1,"text"),
                   GetSQLValueString($_POST['id'], "text"));



// code for entering it into a database.
    mysql_select_db(strato11_members);
    $Result1 = mysql_query($updateSQL) or die(mysql_error());

$updateGoTo = "view_members.php";
if (isset($_SERVER['QUERY_STRING'])) {
$updateGoTo .= (strpos($updateGoTo, '?')) ? "&" : "?";
$updateGoTo .= $_SERVER['QUERY_STRING'];
}
header(sprintf("Location: %s", $updateGoTo));
}?>
