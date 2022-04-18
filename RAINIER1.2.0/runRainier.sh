

#energy
for ENERGY in {1..10}
do
  for J in {1..10}
  do
    echo "const double g_dExIMax = $ENERGY;" > initialState.h
    echo "const double g_dSpI    = $J;" >> initialState.h
    echo "const double g_dParI   = 0;" >> initialState.h

    RUNNUM=${ENERGY}${J}
    echo -e "\n\n######RUNNUM = $RUNNUM#######"
    root -l -q 'RAINIER.C('$RUNNUM')'
    #.q
  done
done
