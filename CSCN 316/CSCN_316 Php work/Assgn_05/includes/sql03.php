<?PHP
// Perform query 04
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_nation");

if (mysqli_connect()) {
    echo "failed to connect to MySQL: " .mysqli_connect_error();
}


$sql09 = "SELECT *
          FROM countries
          WHERE name = 'Spain'";
if($result = mysqli_query($con, $sql09)){
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
        echo "ERROR: Could not connect to execute $sql09. " . mysqli_error($con);
    }


 $sql10 = "SELECT name
           FROM regions
           WHERE name = 'Southern Europe'";
if($result = mysqli_query($con, $sql10)){
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
echo "ERROR: Could not connect to execute $sql10. " . mysqli_error($con);
} 


$sql11 = "SELECT *
           FROM country_stats
           WHERE country_id = 67 AND year = 2018";
if($result = mysqli_query($con, $sql11)){
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
echo "ERROR: Could not connect to execute $sql11. " . mysqli_error($con);
}


$sql12 = "SELECT l.language
          FROM country_languages as cl, languages as l
          WHERE cl.language_id = l.language_id AND cl.country_id = 67";
if($result = mysqli_query($con, $sql12)){
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
echo "ERROR: Could not connect to execute $sql12. " . mysqli_error($con);
}  


// Close connection
mysqli_close($con);

?>