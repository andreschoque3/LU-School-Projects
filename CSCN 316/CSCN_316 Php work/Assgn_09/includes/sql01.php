<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_office");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql01 = "SELECT *
FROM employees WHERE EMPLOYEE_ID = 100";
if($result = mysqli_query($con, $sql01)){
    if(mysqli_num_rows($result) > 0){ 
      
        
        while($row = mysqli_fetch_array($result)){ // work through array of results
        
        echo "<h1>" . $row['FIRST_NAME'] . " " . $row['LAST_NAME'] . "</h1>";
        echo "<td>" . '<img src="data:image/jpeg;base64,'.base64_encode($row['PHOTO']).'" />' . "</td>";

        }
      

        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql01. " . mysqli_error($con);
}
?>