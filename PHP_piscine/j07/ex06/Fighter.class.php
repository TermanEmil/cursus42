<?php

abstract class Fighter
{
    private $fighter_type = "none";

    public function get_fight_type() {return $this->fighter_type;}

    abstract public function fight($target);

    public function __construct($ftype)
    {
        $this->fighter_type = $ftype;
    }
}