<div id="a" class="middle">

    <ul>
        <li><a href="index.php">Home</a></li>
        <li><a href="index.php">Resources</a></li>
        <li><a href="index.php">Forms</a></li>
        <li><a class="current" href="index.php">Staff</a></li>
        <li><a class="current" href="index.php">Emp. Month</a></li>
        <li><a href="index.php">Logout</a></li>
    </ul>

</div>

<div id="b" class="middle">

    <h1>Staff</h1>

</div>

<div id="c" class>

    <?php
        include("sql01.php");
    ?>

    <hr />

    <h1>Employees of the Month</h1>


    <?php
        include("sql02.php");
    ?>

</div>
