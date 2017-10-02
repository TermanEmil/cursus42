<?php

class Lannister
{
    public function     sleepWith($person)
    {
        if (is_subclass_of($person, 'Stark'))
        {
            echo 'Let\'s do this.' . PHP_EOL;
            return True;
        }
        else {
            echo 'Not even if I\'m drunk !' . PHP_EOL;
            return False;
        }
    }
}