<html>
<head>
        <title>Multiplication Table</title>
</head>
<body>
        <form method="post">
                <label>Enter a number: </label>
                <input type="text" name="num">
                <input type="submit" name="submit" value="Generate Table">
        </form>

        <?php
                if(isset($_POST['submit'])) {
                        $num = $_POST['num'];

                        echo "<h2>Multiplication Table for $num</h2>";

                        echo "<table border='5'>";
                        echo "<tr><th>*</th>";

                        for($i=1; $i<=$num; $i++) {
                                echo "<th>$i</th>";
                        }
                        echo "</tr>";

                        for($i=1; $i<=$num; $i++) {
                                echo "<tr><th>$i</th>";
                                for($j=1; $j<=$num; $j++) {
                                        $value = $i * $j;
                                        echo "<td>$value</td>";
                                }
                                echo "</tr>";
                        }
                        echo "</table>";
                }
        ?>
</body>
</html>

