<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

/**
 * @brief CFile
 * Permits to read/write into a file easily
 */
class CFile
{
    function __construct($filename)
    {
        $this->__filename = $filename;

        if (!file_exists($this->__filename))
        {
            $handle = fopen($this->__filename, 'w+');
            fclose($handle);
        }

    }

    function data()
    {
        if ($this->size() == 0)
            return 0;

        $handle = fopen($this->__filename, 'rb');

        $data = fread($handle, $this->size());

        fclose($handle);

        return $data;
    }

    function set_data($data)
    {
        $handle = fopen($this->__filename, 'wb');

        fwrite($handle, $data, strlen($data));

        fclose($handle);
    }

    function add_data($data)
    {
        $old_data = data();

        $handle = fopen($this->__filename, 'wb');

        $new_data = $old_data . $data;

        fwrite($handle, $new_data, strlen($new_data));

        fclose($handle);
    }

    function size()
    {
        return filesize($this->__filename);
    }

    private $__filename;
}

function getJSONData($country = 'France')
{
    $data_file = new CFile('data.json');
    echo $data_file->data();
}

?>
<!DOCTYPE HTML>
<html>
<head>
<script>
window.onload = function() {

var dataPoints = [];

var chart = new CanvasJS.Chart("chartContainer", {
	animationEnabled: true,
	theme: "dark",
	zoomEnabled: true,
	title: {
		text: "Bitcoin Price - 2017"
	},
	axisY: {
		title: "Price in USD",
		titleFontSize: 24,
		prefix: "$"
	},
	data: [{
		type: "line",
		yValueFormatString: "$#,##0.00",
		dataPoints: dataPoints
	}]
});

function addData(data) {
	var dps = data.price_usd;
	for (var i = 0; i < dps.length; i++) {
		dataPoints.push({
			x: new Date(dps[i][0]),
			y: dps[i][1]
		});
	}
	chart.render();
}

addData(<?php getJSONData(); ?>);

}
</script>
</head>
<body>
<div id="chartContainer" style="height: 370px; width: 100%;"></div>
<script src="https://canvasjs.com/assets/script/jquery-1.11.1.min.js"></script>
<script src="https://canvasjs.com/assets/script/jquery.canvasjs.min.js"></script>
</body>
</html>
