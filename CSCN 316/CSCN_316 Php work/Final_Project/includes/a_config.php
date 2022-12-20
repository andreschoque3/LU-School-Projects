<?php
	$path = $_SERVER["SCRIPT_NAME"]; 
		$page=basename($path);
		switch($page) {
		
		case "business.php":
			$CURRENT_PAGE = "Business"; 
			$PAGE_TITLE = "Business News";
			break;
		case "sport.php":
			$CURRENT_PAGE = "Sport"; 
			$PAGE_TITLE = "Sports News";
			break;
		case "location.php":
			$CURRENT_PAGE = "Location";
			$PAGE_TITLE = "Location News";
		case "subscribe.php":
			$CURRENT_PAGE = "Subscribe";
			$PAGE_TITLE = 'Subscribe';
		default:
			$CURRENT_PAGE = "Index";
			$PAGE_TITLE = "Home Page";
	}
?>