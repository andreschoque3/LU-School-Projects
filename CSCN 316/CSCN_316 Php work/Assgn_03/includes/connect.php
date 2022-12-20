<?php
//connect to server and database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_office");

if (mysqli_connect()) {
    echo "failed to connect to MySQL: " .mysqli_connect_error();
}

//perform query
$sql = "SELECT FIRST_NAME as fname,  LAST_NAME as lname FROM employees";
if($result = mysqli_query($con, $sql)){
    if(mysqli_num_rows($result) > 0){
      echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
            echo "<th>lname</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['fname']."</td>";
            echo "<td>".$row['lname']."</td>";
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


$sql2 = "SELECT DISTINCT DEPARTMENT_ID FROM employees";
if($result = mysqli_query($con, $sql2)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>"
          echo "<tr>";
            
             echo "<th>department_id</th>"
          echo "</tr>"
        while($row = mysqli_fetch_array($result)){ //work through array of results
        SELECT DISTINCT department_id FROM employees;
        echo "<tr>";
            
            echo "<td>"."$". number_format($row['DEPARTMENT_ID'],2,".",",")."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql2." . mysqli_error($con);
}


$sql3 = "SELECT * FROM employees 
	ORDER BY FIRST_NAME as fname DESC";
if($result = mysqli_query($con, $sql3)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['fname']."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql3." . mysqli_error($con);
}


$sql4 = "SELECT FIRST_NAME as fname, LAST_NAME as lname, SALARY as salary, salary*.12 PF FROM employees";
if($result = mysqli_query($con, $sql4)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
            echo "<th>lname</th>";
            echo "<th>salary</th>";
            echo "<th>pf</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['fname']."</td>";
            echo "<td>".$row['lname']."</td>";
            echo "<td>"."$". number_format($row['SALARY'],2,".",",")."</td>";
            echo "<td>"."$". number_format(($row['SALARY'] * 0.12),2,".",",")."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql4." . mysqli_error($con);
}


$sql5 = "SELECT EMPLOYEE_ID, FIRST_NAME as fname, LAST_NAME as lname, SALARY as salary 
    FROM employees 
    ORDER BY salary";
if($result = mysqli_query($con, $sql5)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
            echo "<th>lname</th>";
            echo "<th>EMPLOYEE_ID</th>";
            echo "<th>salary</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['fname']."</td>";
            echo "<td>".$row['lname']."</td>";
            echo "<td>"."$". number_format($row['EMPLOYEE_ID'],2,".",",")."</td>";
            echo "<td>"."$". number_format($row['SALARY'],2,".",",")."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql5." . mysqli_error($con);
}

$sql6 = "SELECT SUM(salary) as sal FROM employees";
if($result = mysqli_query($con, $sql6)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
          
            echo "<th>salary</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            
            echo "<td>"."$". number_format($row['sal'],2,".",",")."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql6." . mysqli_error($con);
}


$sql7 = "SELECT MAX(salary), MIN(salary) FROM employees";
if($result = mysqli_query($con, $sql7)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
          
            echo "<th>salary</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            
            echo "<td>"."$". number_format($row['SALARY'],2,".",",")."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql7." . mysqli_error($con);
}
// close the connection
mysqli_close($con);
?>
