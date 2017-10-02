<?php

class Jaime extends Lannister
{
    public function     sleepWith($person)
    {
        if (is_subclass_of($person, 'Lannister') and !is_a($person, 'Tyrion'))
        {
            echo 'With pleasure, but only in a tower in Winterfell, then.' . PHP_EOL;
            return True;
        }
        parent::sleepWith($person);
    }
}