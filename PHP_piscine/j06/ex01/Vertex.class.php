<?php

require_once ('Color.class.php');

Class Vertex
{
	static					$verbose = FALSE;

	private					$_x = 0;
	private					$_y = 0;
	private					$_z = 0;
	private					$_w = 1.0;
	private					$_color;
	
	/*
	** Public
	*/

	function                add(Vertex $vert)
    {
        return new Vertex([$this->_x + $vert->get_x(), $this->_y + $vert->get_y(), $this->_z + $vert->get_z()]);
    }

    function                sub(Vertex $vert)
    {
        return new Vertex([$this->_x - $vert->get_x(), $this->_y - $vert->get_y(), $this->_z - $vert->get_z()]);
    }

	/*
	** Geters and seter
	*/

	function				get_x() {return $this->_x;}
	function				get_y() {return $this->_y;}
	function				get_z() {return $this->_z;}
	function				get_w() {return $this->_w;}
	function				get_color() {return $this->_color;}

	function				get_coords()
	{
		return ['x' => $this->_x,
				'y' => $this->_y,
				'z' => $this->_z];
	}

	function				set_x($x) {$this->_x = $x;}
	function				set_y($y) {$this->_y = $y;}
	function				set_z($z) {$this->_z = $z;}
	function				set_w($w) {$this->_w = $w;}
	function				set_color($cl) {$this->_color = $cl;}

	function				set_coords(array $coords)
	{
		if (array_key_exists('x', $coords) && array_key_exists('y', $coords) && array_key_exists('z', $coords))
		{
			$this->_x = $coords['x'];
			$this->_y = $coords['y'];
			$this->_z = $coords['z'];
		}
		else if (array_key_exists(0, $coords) && array_key_exists(1, $coords) && array_key_exists(2, $coords))
		{
			$this->_x = $coords[0];
			$this->_y = $coords[1];
			$this->_z = $coords[2];
		}
		else
		{
			echo 'Invalid arguments' . PHP_EOL;
			exit(1);
		}
	}

	/*
	** Speial
	*/

	function				__construct($kwargs)
	{
		$this->set_coords($kwargs);

		if (array_key_exists('w', $kwargs))
			$this->set_w($kwargs['w']);

		if (array_key_exists('color', $kwargs))
			$this->set_color($kwargs['color']);
		else if (array_key_exists('cl', $kwargs))
			$this->set_color($kwargs['cl']);
		else
			$this->_color = new Color(Color::$cl_white);
        if (self::$verbose)
            echo $this . ' constructed' . PHP_EOL;
	}

	function				__destruct()
	{
        if (self::$verbose)
            echo $this . ' destructed' . PHP_EOL;
	}

	function				__toString()
	{
		return sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f%s )",
			$this->_x, $this->_y, $this->_z, $this->_w,
			(self::$verbose) ? (', ' . $this->_color) : "");
	}

	/*
	** Static
	*/

	static					function	doc()
	{
        $file_path = dirname(__FILE__) . '/Vertex.doc.txt';
		if (file_exists($file_path))
			return file_get_contents($file_path) . PHP_EOL;
		else
			return "Couldn't find " . $file_path . PHP_EOL;
	}

	/*
	** Private
	*/

	/*
	** Private static
	*/
}