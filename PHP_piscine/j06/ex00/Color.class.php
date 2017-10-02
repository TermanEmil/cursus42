<?php

Class Color
{
	public static	$verbose = FALSE;

	public static	$cl_white = [255, 255, 255];
	public static	$cl_red = [255, 0, 0];
	public static	$cl_green = [0, 255, 0];
	public static	$cl_blue = [0, 0, 255];

	public			$red = 0;
	public			$green = 0;
	public			$blue = 0;

	const		CL_MAP = ['red', 'green', 'blue'];

	/*
	** Public
	*/

	function				set_rgb(array $kwargs, $neg)
	{
		if (($ret = self::_check_cl_format($kwargs, $neg)) >= 0)
		{
			foreach (self::CL_MAP as $cl)
				$this->$cl = min(255, max(0, $ret[$cl[0]]));
		}	
	}

	function				add(Color $color)
	{
		$result = ['red' => 0, 'green' => 0, 'blue' => 0];
		foreach (self::CL_MAP as $cl)
			$result[$cl] = min(255, max(0, $this->$cl + $color->$cl));
		return (new Color($result));
	}

	function				sub(Color $color)
	{
        $result = ['red' => 0, 'green' => 0, 'blue' => 0];
		foreach (self::CL_MAP as $cl)
			$result[$cl] = min(255, max(0, $this->$cl - $color->$cl));
        return (new Color($result));
	}

	function				mult($val)
	{
        $result = ['red' => 0, 'green' => 0, 'blue' => 0];
		foreach (self::CL_MAP as $cl)
			$result[$cl] = min(255, max(0, $this->$cl * $val));
        return (new Color($result));
	}

	/*
	** Special
	*/

	function				__construct(array $kwargs)
	{
		if (count($kwargs) == 0)
			$this->set_rgb(['rgb' => 0], TRUE);
		else
			$this->set_rgb($kwargs, TRUE);
		if (self::$verbose)
			echo $this->__toString() . ' constructed.' . PHP_EOL;
	}

	function				__destruct()
	{
		if (self::$verbose)
			echo $this->__toString() . ' destructed.' . PHP_EOL;
	}

	function				__toString()
	{
		return sprintf("Color( red: %3d, green: %3d, blue: %3d )",
			$this->red, $this->green, $this->blue);
	}

	/*
	** Static
	*/

	static					function	doc()
	{
		$file_path = dirname(__FILE__) . '/Color.doc.txt';
		if (file_exists($file_path))
			return file_get_contents($file_path) . PHP_EOL;
		else
			return "Couldn't find $file_path" . PHP_EOL;
	}

	/*
	** Private static
	*/

	private static function	_parse_color(array $kwargs, $neg)
	{
		if (array_key_exists('rgb', $kwargs))
		{
			$kwargs['rgb'] = intval($kwargs['rgb']);
			if ($neg and ($kwargs['rgb'] >= 256 ** 3 or $kwargs['rgb'] < 0))
				return (-1);
			return ['r' => $kwargs['rgb'] >> 16,
					'g' => $kwargs['rgb'] >> 8 & 255,
					'b' => $kwargs['rgb'] & 255];
		}
		else if (array_key_exists('r', $kwargs) && array_key_exists('g', $kwargs) && array_key_exists('b', $kwargs))
		{
			foreach (['r', 'g', 'b'] as $key)
				if ($neg and ($kwargs[$key] < 0 OR $kwargs[$key] > 255))
					return (-2);
			return ['r' => $kwargs['r'],
					'g' => $kwargs['g'],
					'b' => $kwargs['b']];
		}
		else if (array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs))
		{
			foreach (self::CL_MAP as $key)
				if ($neg and ($kwargs[$key] < 0 OR $kwargs[$key] > 255))
					return (-2);
			return ['r' => $kwargs['red'],
					'g' => $kwargs['green'],
					'b' => $kwargs['blue']];
		}
		else if (count($kwargs) == 3)
			return ['r' => $kwargs[0],
					'g' => $kwargs[1],
					'b' => $kwargs[2]];
		else
			return (-3);
	}

	private static function	_check_cl_format(array $kwargs, $neg)
	{
		if (($ret = self::_parse_color($kwargs, $neg)) < 0) {
            echo [-1 => 'rgb can only be from: [0; 256 ^ 3 = 16777216]',
                    -2 => 'rgb values can only be from: [0; 255]',
                    -3 => 'Invalid arguments'][$ret] . PHP_EOL;
            return (FALSE);
        }
		else
			return ($ret);
	}
}