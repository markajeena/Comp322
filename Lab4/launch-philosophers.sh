#Mark Ajina
#Lab4: Rice Rice and Rice
#this is a bash script for launch-philosophers, that simulates
#a solution for the dining philosopher problem

program=./dining-p
seats=$1
position=$2

if [ $# -gt 2 ];
then
echo "Error: input less arguments";
exit 1;
fi

#if there's no number of seats given
if [ -z ${seats} ]; 
then
echo "Enter a number of seats (must be positive).";
exit 1;
fi


#if there's no position number given
if [ -z ${position} ];
then
echo "Enter a number for a philosopher(must be positve)";
exit 1;
fi


#if there's less seats than philosophers/position given
if [ ${seats} -lt ${position} ];
then
echo "Error: not enough seats.";
exit 1;
fi

cycle=1
while [ ${cycle} -le ${position} ] ; do
      ${program} ${seats} ${cycle} &
      echo "Philosopher #${cycle}'s PID is" $!
      cycle=$(( $cycle + 1 ))
done
