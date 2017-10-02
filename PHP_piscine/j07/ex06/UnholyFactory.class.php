<?php

class UnholyFactory
{
    private $_soldier_types = [];

    public function absorb($person)
    {
        if ($person instanceof Fighter)
        {
            if (isset($this->_soldier_types[$person->get_fight_type()]))
                echo '(Factory already absorbed a fighter of type ' . $person->get_fight_type() . ')' . PHP_EOL;
            else {
                $this->_soldier_types[$person->get_fight_type()] = $person;
                echo '(Factory absorbed a fighter of type ' . $person->get_fight_type() . ')' . PHP_EOL;
            }
        }
        else
            echo '(Factory can\'t absorb this, it\'s not a fighter)' . PHP_EOL;
    }

    public function fabricate($rf)
    {
        if (!isset($this->_soldier_types[$rf]))
        {
            echo '(Factory hasn\'t absorbed any fighter of type ' . $rf .')' . PHP_EOL;
            return null;
        }
        echo '(Factory fabricates a fighter of type ' . $this->_soldier_types[$rf]->get_fight_type() .')' . PHP_EOL;
        return $this->_soldier_types[$rf];
    }
}