<?php
	$path = $_SERVER["SCRIPT_NAME"]; 
		$page=basename($path);
		switch($page) {
		
		case "about.php":
			$CURRENT_PAGE = "About"; 
			$PAGE_TITLE = "About Us";
			break;
		case "contact.php":
			$CURRENT_PAGE = "Contact"; 
			$PAGE_TITLE = "Contact Us";
			break;
		default:
			$CURRENT_PAGE = "Index";
			$PAGE_TITLE = "Home Page";
	}
?>