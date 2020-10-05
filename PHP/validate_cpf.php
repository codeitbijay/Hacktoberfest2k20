<?php
/* 
 * Creating Interface for Exceptions 
 */
interface ExceptionInterface {
}

/*
 * Creating Exception exclusive to CPF. It helps a lot to discover the type of Exception
 */
class InvalidCpfException extends \InvalidArgumentException implements ExceptionInterface
{

}

/**
 * CPF definition:
 * 
 * The Register of Individuals is the register maintained by the Federal Revenue of Brazil in which any natural persons, regardless of age or nationality, including those who have died, can register once. 
 * Each registrant is uniquely identified by an 11 decimal digit CPF registration number. Example: 123.456.789-10
 * 
 */
class Cpf
{
    private $cpf;

    /**
     * Cpf constructor.
     * @param string $cpf
     */
    public function __construct($cpf)
    {
        if ($this->validate($cpf) === false) {
            throw new InvalidCpfException;
        }
        return $this->cpf = $cpf;
    }

    public function __toString()
    {
        return $this->cpf;
    }

    private function validate($cpf)
    {

        // Extract only the numbers
        $cpf = preg_replace('/[^0-9]/is', '', $cpf);

        // Checks if all digits were entered correctly
        if (strlen($cpf) != 11) {
            return false;
        }
        // Checks if a sequence of repeated digits has been entered. Ex: 111.111.111-11
        if (preg_match('/(\d)\1{10}/', $cpf)) {
            return false;
        }
        // Does the calculation to validate the CPF
        for ($t = 9; $t < 11; $t++) {
            for ($d = 0, $c = 0; $c < $t; $c++) {
                $d += $cpf{$c} * (($t + 1) - $c);
            }
            $d = ((10 * $d) % 11) % 10;
            if ($cpf{$c} != $d) {
                return false;
            }
        }
        return true;
    }
}

//example call:

try{
    $cpf = new Cpf('123.456.789-10');
    echo "CPF: {$cpf}";
} catch(InvalidCpfException $e){
    echo "Invalid CPF";
} catch (Exception $e){
    echo "Unexpected error";
}