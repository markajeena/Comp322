

EXEC = dining-p
seats = $1
child = $!
pid = ()

if [ $1 -gt 2 ];
then
echo "Error: input less arguments";
exit 1;

fi

#creates a seat for every philosopher
for ((i=0; $i<$SEATS; i+=1))
do

	./$EXEC $SEATS $i 

#for every pid for child
	pid[${i}]=$! 
done
