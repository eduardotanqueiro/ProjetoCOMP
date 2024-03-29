#!/usr/bin/env bash
#
#  Utilização
#    bash test.sh ./path/to/jucompiler
#
#  Funcionalidade
#  Compara todos os casos de teste na pasta meta1
#  Cria o ficheiro *casoteste*.out_temp com resultado de correr cada caso de teste

if [[ -z "$1" ]]; then
    echo "Missing argument executable"
    echo "Usage: $0 executable"
    echo "Example: $0 ./path/to/jucompiler"
    exit 1
fi

exe="$1"

accepted=0
total=0



if [[ -d meta3 ]]; then
    for inp in meta3/*.java; do
    total=$(( $total + 1 ))
        echo "$inp"
        out=${inp%.java}.out
        tmp=${inp%.java}.out_temp
        flag="-s"
        if [[ "$inp" == *_s.java ]]; then
            flag=""
        fi
        if $exe $flag < "$inp" > "$tmp"; then 
            lines=$(diff --strip-trailing-cr  <(sort $tmp) <(sort $out) | wc -l) #check files ignoring line order
            #lines=$(diff --strip-trailing-cr $out $tmp | wc -l)
            if [[ $lines -gt 0 ]]; then
                echo " Wrong Answer, run 'diff --strip-trailing-cr  <(sort $tmp) <(sort $out)' to see the differences"
                #echo " Wrong Answer, run 'diff $out $tmp' to see the differences"
            else
                accepted=$(( $accepted + 1 ))
            fi
        else
            echo " Runtime Error, failed to execute '$exe'"
        fi
    done
fi

echo "Accepted: $accepted / $total"