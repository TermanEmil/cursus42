<?php

require_once 'Vertex.class.php';
require_once 'Vector.class.php';

Class Matrix
{
    static					$verbose = FALSE;

    const   IDENTITY = ['preset' =>
                        [[1.0, 0.0, 0.0, 0.0],
                         [0.0, 1.0, 0.0, 0.0],
                         [0.0, 0.0, 1.0, 0.0],
                         [0.0, 0.0, 0.0, 1.0]], 'type' => 'identity'];

    const   SCALE = ['preset' => self::IDENTITY['preset'], 'type' => 'scale'];

    const   RX = ['preset' =>
                    [[1, 0,     0,      0  ],
                     [0, 'cos', '-sin', 0  ],
                     [0, 'sin', 'cos',  0  ],
                     [0,  0,     0,     1.0]], 'type' => 'rx'];

    const   RY = ['preset' =>
                    [['cos',  0,    'sin', 0],
                     [0,      1,        0, 0],
                     ['-sin', 0,    'cos', 0],
                     [0,      0,    0,   1.0]], 'type' => 'ry'];

    const   RZ = ['preset' =>
                 [['cos', '-sin',   0, 0],
                  ['sin',  'cos',   0, 0],
                  [0,       0,      1, 0],
                  [0,       0,      0, 1.0]], 'type' => 'rz'];

    const   TRANSLATION = ['preset' =>
                          [[1, 0, 0, 'x'],
                           [0, 1, 0, 'y'],
                           [0, 0, 1, 'z'],
                           [0, 0, 0, 1.0]], 'type' => 'translation'];

    private                 $_value;

    /*
    ** Public
    */

    function                mult(Matrix $rhs)
    {
        $preset = [];
        $tab1 = $this->_value['preset'];
        $tab2 = $rhs->get_val();

        for ($i = 0; $i < 4; $i += 1)
            for ($j = 0; $j < 4; $j += 1)
            {
                $preset[$i][$j] = 0;
                for ($k = 0; $k < 4; $k += 1)
                    $preset[$i][$j] += $tab1[$i][$k] * $tab2[$k][$j];
            }
        return new Matrix(['preset' => $preset]);
    }

    function                transformVertex(Vertex $vtx)
    {
        $result['x'] =  $this->_value['preset'][0][0] * $vtx->get_x() +
                        $this->_value['preset'][0][1] * $vtx->get_y() +
                        $this->_value['preset'][0][2] * $vtx->get_z() +
                        $this->_value['preset'][0][3] * $vtx->get_w();

        $result['y'] =  $this->_value['preset'][1][0] * $vtx->get_x() +
                        $this->_value['preset'][1][1] * $vtx->get_y() +
                        $this->_value['preset'][1][2] * $vtx->get_z() +
                        $this->_value['preset'][1][3] * $vtx->get_w();

        $result['z'] =  $this->_value['preset'][2][0] * $vtx->get_x() +
                        $this->_value['preset'][2][1] * $vtx->get_y() +
                        $this->_value['preset'][2][2] * $vtx->get_z() +
                        $this->_value['preset'][2][3] * $vtx->get_w();

        $result['w'] =  $this->_value['preset'][3][0] * $vtx->get_x() +
                        $this->_value['preset'][3][1] * $vtx->get_y() +
                        $this->_value['preset'][3][2] * $vtx->get_z() +
                        $this->_value['preset'][3][3] * $vtx->get_w();

        return new Vertex($result);
    }

    /*
    ** Geters and seter
    */

    function                get_val() {return $this->_value['preset'];}

    /*
    ** Speial
    */

    function				__construct(array $kwargs)
    {
        if (!array_key_exists('preset', $kwargs)) {
            echo 'Invalid arguments' . PHP_EOL;
            exit(1);
        }
        $ret = $this->_read_kwargs($kwargs);
        if ($ret === 0) {
            if (self::$verbose)
                echo 'Matrix ' . (($this->_value['type'] != 'undefined') ? strtoupper($this->_value['type']) : "") . ' instance constructed' . PHP_EOL;
        }
        else
        {
            echo "\t" . $ret . PHP_EOL;
            exit(1);
        }
    }

    function				__destruct()
    {
        if (self::$verbose)
            echo 'Matrix instance destructed' . PHP_EOL;
    }

    function				__toString()
    {
        $tab = $this->_value['preset'];
        $lens = [];
        for ($j = 0; $j < 4; $j += 1)
            $lens[] = self::_max_len_on_column($tab, $j);
        $str = sprintf("M | %$lens[0]s | %$lens[1]s | %$lens[2]s | %$lens[3]s",
            'vtcX', 'vtcY', 'vtcZ', 'vtx0');
        $str .= PHP_EOL;

        $n = strlen($str) - 1;
        for ($i = 0; $i < $n; $i += 1)
            $str .= '-';

        $keys = ['x', 'y', 'z', 'w'];
        for ($i = 0; $i < 4; $i += 1)
        {
            $str .= PHP_EOL;
            $str .= sprintf("%s | %$lens[0].2f | %$lens[1].2f | %$lens[2].2f | %$lens[3].2f",
                $keys[$i], $tab[$i][0], $tab[$i][1], $tab[$i][2], $tab[$i][3]);
        }
        return $str;
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

    private function        _read_kwargs($kwargs)
    {
        if (!array_key_exists('preset', $kwargs))
            return ('preset is not set');
        if (isset($kwargs['preset']['preset']))
        {
            $this->_value['preset'] = $kwargs['preset']['preset'];
            $this->_value['type'] = (isset($kwargs['preset']['type'])) ? $kwargs['preset']['type'] : 'undefined';
        }
        else
        {
            $this->_value['preset'] = $kwargs['preset'];
            $this->_value['type'] = 'undefined';
        }

        switch (strtolower($this->_value['type']))
        {
            case self::SCALE['type']:
                if (!isset($kwargs['scale']))
                    return "Note: scale factor must be set when preset is worth SCALE.";

                $this->_value['preset'] = $this->_scalarMult(floatval($kwargs['scale']));
                break ;

            case self::RX['type']:
            case self::RY['type']:
            case self::RZ['type']:
                if (!isset($kwargs['angle']))
                    return 'Note: angle factor must be set when preset is worth RX, RY or RZ.';
                $this->_read_rotation($kwargs['angle']);
                break ;

            case self::TRANSLATION['type']:
                if (!isset($kwargs['vtc']))
                    return 'Note: vtc factor must be set when preset is worth TRANSLATION.';
                $this->_value['preset'][0][3] = $kwargs['vtc']->get_x();
                $this->_value['preset'][1][3] = $kwargs['vtc']->get_y();
                $this->_value['preset'][2][3] = $kwargs['vtc']->get_z();
                break ;
        }
        return 0;
    }

    private function        _scalarMult($scalar)
    {
        $preset = [];
        $tab = $this->_value['preset'];

        for ($i = 0; $i < 4; $i += 1)
            for ($j = 0; $j < 4; $j += 1)
            {
                if ($i == 3 or $j == 3)
                    $preset[$i][$j] = $tab[$i][$j];
                else
                    $preset[$i][$j] = $tab[$i][$j] * $scalar;
            }
        return $preset;
    }

    private function        _read_rotation($angle)
    {
        for ($i = 0; $i < 3; $i += 1)
            for ($j = 0; $j < 3; $j += 1)
                switch (strval($this->_value['preset'][$i][$j]))
                {
                    case 'sin':
                        $this->_value['preset'][$i][$j] = sin($angle);
                        break;
                    case '-sin':
                        $this->_value['preset'][$i][$j] = -sin($angle);
                        break;
                    case 'cos':
                        $this->_value['preset'][$i][$j] = cos($angle);
                        break;
                }
    }

    /*
    ** Private static
    */

    private static function _max_len_on_column($tab, $j)
    {
        $max = 0;
        for ($i = 0; $i < 4; $i += 1)
        {
            $tmp = strlen(sprintf("%+.2f", $tab[$i][$j]));
            if ($tmp > $max)
                $max = $tmp;
        }
        return $max;
    }
}