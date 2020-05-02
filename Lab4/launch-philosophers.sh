

EXEC=dining-p
seats=$1
child=$!
position=$2
pid=()

if [ $# -gt 2 ];
then
echo "Error: input less arguments";
exit 1;
fi

#if there's no number of seats given
if [ -z ${seats} && ${seats} -lt 0 ] ; 
then
echo "Enter a number of seats (must be positive).";
exit 1;
fi

#if there's no position number given
if [ -z ${position} &&  ${position} -lt 0 ] ; then
echo "Enter a number for a philosopher(must be positve)";
exit 1;
fi


#if there's less seats than philosophers/position given
if [ ${seats} -lt ${position} ] ; then
      echo "Error: not enough seats.";
      exit 1;
fi

#creates a seat for every philosopher
for ((i=0; $i<$SEATS; i+=1))
do

	./$EXEC $SEATS $i 

#for every pid for child
	pid[${i}]=$! 
done
wait
