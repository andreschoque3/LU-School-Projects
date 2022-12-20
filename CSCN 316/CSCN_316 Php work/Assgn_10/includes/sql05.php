<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_nation");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql05 = "SELECT vips.name as vip, guests.name as guest
FROM vips, guests
WHERE vip.vips_id = guest.guests_id";

if($result = mysqli_query($con, $sql05)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
        echo "<th>VIP Name </th>";
        echo "<th>Guest Name</th>";
        echo "</tr>"; 

        while($row = mysqli_fetch_array($result)){ // work through array of results
        echo "<tr>";
        echo "<td>" . $row['vip'] . "</td>";
        echo "<td>" . $row['guest'] . "</td>";
        echo "</tr>";
        }
        echo "</table>";
      
        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql05. " . mysqli_error($con);
}
?>