<?php

include_once('IFighter.class.php');

class NightsWatch
{
    private     $watchers = [];

    public function recruit($person)
    {
        $this->watchers[] = $person;
    }

    public function fight()
    {
        foreach ($this->watchers as $wathcer) {
            if ($wathcer instanceof IFighter)
                $wathcer->fight();
        }
    }
}