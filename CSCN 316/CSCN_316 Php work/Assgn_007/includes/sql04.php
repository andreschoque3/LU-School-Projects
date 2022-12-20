<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_office");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql01 = "SELECT * FROM employees ";

if($result = mysqli_query($con, $sql01)){
    if(mysqli_num_rows($result) > 0){ 
        echo "<table>";
        echo "<tr>";
        echo "<th>First Name</th>";
        echo "<th>Last Name</th>";
        echo "<th>Phone Number</th>";
        echo "</tr>";

        while($row = mysqli_fetch_array($result)){ // work through array of results
        echo "<tr>";
        echo "<td>" . $row['FIRST_NAME'] . "</td>";
        echo "<td>" . $row['LAST_NAME'] . "</td>";
        echo "<td>" . $row['PHONE_NUMBER'] . "</td>";
        echo "</tr>";

        }
        echo "</table>";

        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql01. " . mysqli_error($con);
}
 
// Close connection
// mysqli_close($con);
?>