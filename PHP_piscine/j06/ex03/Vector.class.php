<?php

require_once ('Vertex.class.php');

Class Vector
{
	static					$verbose = FALSE;
	private					$_x = 0;
	private					$_y = 0;
	private					$_z = 0;
	private					$_w = 0.0;

	/*
	** Public
	*/

	function                magnitude()
    {
        return (sqrt($this->_x ** 2 + $this->_y ** 2 + $this->_z ** 2));
    }

    function                normalize()
    {
        $mg = $this->magnitude();
        return $this->scalarProduct(($mg != 0) ? (1 / $mg) : 0);
    }

    function                add(Vector $rhs)
    {
        $dest = new Vertex([$this->_x + $rhs->get_x(), $this->_y + $rhs->get_y(), $this->_z + $rhs->get_z()]);
        return new Vector(['dest' => $dest]);
    }

    function                sub(Vector $rhs)
    {
        $dest = new Vertex([$this->_x - $rhs->get_x(), $this->_y - $rhs->get_y(), $this->_z - $rhs->get_z()]);
        return new Vector(['dest' => $dest]);
    }

    function                scalarProduct($k)
    {
        return new Vector(['dest' => new Vertex([$this->_x * $k, $this->_y * $k, $this->_z * $k])]);
    }

    function                opposite()
    {
        return $this->scalarProduct(-1);
    }

    function                dotProduct(Vector $rhs)
    {
        return $this->_x * $rhs->get_x() + $this->_y * $rhs->get_y() + $this->_z * $rhs->get_z();
    }

    function                cos(Vector $rhs)
    {
        $tmp = $this->magnitude() * $rhs->magnitude();
        return ($tmp == 0) ? 0 : $this->dotProduct($rhs) / $tmp;
    }

    function                crossProduct(Vector $rhs)
    {
        $dest = new Vertex([$this->_y * $rhs->get_z() - $this->_z * $rhs->get_y(),
                            $this->_z * $rhs->get_x() - $this->_x * $rhs->get_z(),
                            $this->_x * $rhs->get_y() - $this->_y * $rhs->get_x()]);
        return new Vector(['dest' => $dest]);
    }

	/*
	** Geters and seter
	*/

	function				get_x() {return $this->_x;}
	function				get_y() {return $this->_y;}
	function				get_z() {return $this->_z;}
	function				get_w() {return $this->_w;}
	function				get() {return ['x' => $this->_x, 'y' => $this->_y,  'z' => $this->_z];}

	/*
	** Speial
	*/

	function				__construct(array $kwargs)
	{
        if (array_key_exists('orig', $kwargs))
            $orig = $kwargs['orig'];
        else
            $orig = new Vertex([0, 0, 0, 'w' => 1]);
        if (!array_key_exists('dest', $kwargs))
        {
            echo 'Invalid arguments' . PHP_EOL;
            exit(1);
        }
        $this->_set($orig, $kwargs['dest']);
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
		return sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )",
			$this->_x, $this->_y, $this->_z, $this->_w);
	}

	/*
	** Static
	*/

	static function         doc()
	{
		$file_path = dirname(__FILE__) . '/Vector.doc.txt';
		if (file_exists($file_path))
			return file_get_contents($file_path) . PHP_EOL;
		else
			return "Couldn't find " . $file_path . PHP_EOL;
	}

	/*
	** Private
	*/

    private function        _set(Vertex $orig, Vertex $dest)
    {
        $this->_x = $dest->get_x() - $orig->get_x();
        $this->_y = $dest->get_y() - $orig->get_y();
        $this->_z = $dest->get_z() - $orig->get_z();
    }

	/*
	** Private static
	*/
}