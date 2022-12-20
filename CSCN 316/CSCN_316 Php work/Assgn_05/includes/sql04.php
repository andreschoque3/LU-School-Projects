<?PHP
// Perform query 02
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_nation");

if (mysqli_connect()) {
    echo "failed to connect to MySQL: " .mysqli_connect_error();
}


$sql13 = "SELECT *
          FROM countries
          WHERE name = 'Colombia'";
if($result = mysqli_query($con, $sql13)){
    if(mysqli_num_rows($result) > 0){ 
        
        while($row = mysqli_fetch_array($result)){ // work through array of results
        
        echo "<h1>" . $row['name'] . "-" . $row['country_id'] . "</h1>";

        }

        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
    } else{
        echo "ERROR: Could not connect to execute $sql13. " . mysqli_error($con);
    }


$sql14 = "SELECT name
           FROM regions
           WHERE name = 'South America'";
if($result = mysqli_query($con, $sql14)){
if(mysqli_num_rows($result) > 0){ 

while($row = mysqli_fetch_array($result)){ // work through array of results
    
    echo "<h1>" . $row['name'] . "</h1>";

}

// Free result set
mysqli_free_result($result);
} else{
echo "No records matching your query were found.";
}
} else{
echo "ERROR: Could not connect to execute $sql14. " . mysqli_error($con);
}


$sql15 = "SELECT *
           FROM country_stats
           WHERE country_id = 48 AND year = 2018";
if($result = mysqli_query($con, $sql15)){
if(mysqli_num_rows($result) > 0){ 


while($row = mysqli_fetch_array($result)){ // work through array of results

    echo "<h1>" . "pop =" . " " . number_format($row['population'], 0) . "</h1>";

}

// Free result set
mysqli_free_result($result);
} else{
echo "No records matching your query were found.";
}
} else{
echo "ERROR: Could not connect to execute $sql15. " . mysqli_error($con);
}    


$sql16 = "SELECT l.language
          FROM country_languages as cl, languages as l
          WHERE cl.language_id = l.language_id AND cl.country_id = 48";
if($result = mysqli_query($con, $sql16)){
if(mysqli_num_rows($result) > 0){ 


while($row = mysqli_fetch_array($result)){ // work through array of results

    echo "<h1>" . "Lan =" . " " . $row['language'] . "</h1>";
    


}

// Free result set
mysqli_free_result($result);
} else{
echo "No records matching your query were found.";
}
} else{
echo "ERROR: Could not connect to execute $sql16. " . mysqli_error($con);
}  
// Close connection
mysqli_close($con);
?>