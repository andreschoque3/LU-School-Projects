<?php
//connect to server and database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_office");

if (mysqli_connect()) {
    echo "failed to connect to MySQL: " .mysqli_connect_error();
}

//perform query
$sql = "SELECT * FROM employees LIMIT 25";
if($result = mysqli_query($con, $sql)){
    if(mysqli_num_rows($result) > 0){
        echo '<table></table>';
        echo "<tr></tr>";
        echo "<th>first name</th>";
        echo "<th>last name</th>";
        echo "<th>hire date</th>";
        echo "<th>salary</th>";
        echo "<th>email</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
            echo "<tr></tr>";
            echo "<td>". $row['FIRST_NAME'] . "</td>";
            echo "<td>". $row['LAST_NAME'] . "</td>";
            echo "<td>". $row['HIRE_DATE'] . "</td>";
            echo "<td>". $row['SALARY'] . "</td>";
            echo "<td>". $row['EMAIL'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql." . mysqli_error($con);
}

// close the connection
mysqli_close($con);
?>
