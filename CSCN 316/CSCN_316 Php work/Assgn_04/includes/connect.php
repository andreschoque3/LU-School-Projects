<?php
//connect to server and database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_office");

if (mysqli_connect()) {
    echo "failed to connect to MySQL: " .mysqli_connect_error();
}

//perform query
$sql = "SELECT COUNT(EMPLOYEE_ID) as cemp FROM employees";
if($result = mysqli_query($con, $sql)){
    if(mysqli_num_rows($result) > 0){
      echo "<table>";
        echo "<tr>";
            echo "<th>No of Emps</th>";
        
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['cemp']."</td>";
            
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


$sql2 = "SELECT COUNT(DISTINCT job_id) as id  FROM employees";
if($result = mysqli_query($con, $sql2)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>"
          echo "<tr>";
             echo "<th>Job Id:</th>";
          echo "</tr>"
        while($row = mysqli_fetch_array($result)){ //work through array of results
        SELECT DISTINCT department_id FROM employees;
        echo "<tr>";
            echo "<td>"."$". number_format($row['JOB_ID'],2,".",",")."</td>";
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


$sql3 = "SELECT UPPER(first_name) as fname FROM employees";
if($result = mysqli_query($con, $sql3)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
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


$sql4 = "SELECT SUBSTRING(first_name,1,3) as fname
     FROM employees";
if($result = mysqli_query($con, $sql4)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
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


$sql5 = "SELECT 171*214+625 Result";
if($result = mysqli_query($con, $sql5)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>Result</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['RESULT']."</td>";
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

$sql6 = "SELECT  CONCAT(first_name,' ', last_name) as EmpName FROM employees";
if($result = mysqli_query($con, $sql6)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>EmpName</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
            echo "<td>".$row['LAST_NAME']."</td>";
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


$sql7 = "SELECT TRIM(first_name) as fname FROM employees";
if($result = mysqli_query($con, $sql7)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
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


$sql8 = "SELECT first_name,last_name, LENGTH(first_name)+LENGTH(last_name)  as leng
    FROM employees";
if($result = mysqli_query($con, $sql8)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>leng</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['LENG']."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql8." . mysqli_error($con);
}

$sql9 = "SELECT * FROM employees  WHERE  first_name as fname REGEXP  '[0-9]";
if($result = mysqli_query($con, $sql9)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql9." . mysqli_error($con);
}


$sql10 = "SELECT employee_id as empid, first_name as fname FROM employees  LIMIT 10";
if($result = mysqli_query($con, $sql10)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
            echo "<th>employee_id</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
            echo "<td>".$row['EMPLOYEE_ID']."</td>";
        echo "</tr>";
        } 
        echo "</table>";
       // free result set
       mysqli_free_result($result);  
    }else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql10." . mysqli_error($con);
}


$sql11 = "SELECT first_name as fname, last_name as lname, round(salary/12,2) as monthSalary  FROM employees";
if($result = mysqli_query($con, $sql11)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
            echo "<th>fname</th>";
            echo "<th>lname</th>";
            echo "<th>monthSalary</th>";
        echo "</tr>";
        while($row = mysqli_fetch_array($result)){ //work through array of results
        echo "<tr>";
            echo "<td>".$row['FIRST_NAME']."</td>";
            echo "<td>".$row['LAST_NAME']."</td>";
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
    echo "ERROR: Could not connect to execute $sql11." . mysqli_error($con);
}
// close the connection
mysqli_close($con);
?>
