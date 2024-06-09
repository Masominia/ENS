Newly added main models in version 8:

CMS.xml

Description:              Based on the 2008 Strukov’s paper 
Input models:             Vt1 is a periodic voltage input and Vt3 is half positive half negative periodic input
Memristor models:         Based on the Strukov’s paper

-__________________________________-


VMS.xml

Description:              Based on the 2011 Chang’s paper 
Input models:             Vt1 is a periodic voltage input and Vt2 is half positive half negative periodic input
Memristor models:         Based on the Chang’s paper


-__________________________________-


Mott.xml

Description:              Based on the 2012 Pickett’s paper (sub-100)
Input models:             Vt1 is a linear input from 0 to 2V and to 0 again
Memristor models:         Based on the 2012 Pickett’s paper (sub-100)
Goal:                     simulating a current controlled memristor capable of changing the state in sub-nano second, used for the neuristor.


-__________________________________-


VMS_Synapse.xml

Description:              Based on the 2009 Pershin’s paper 
Input models:             Vt1 is a periodic input voltage
Memristor models:         Based on the 2009 Pershin’s paper
Goal:                     simulating a voltage controlled memristor with threshold which is suitable for acting as synapse


-__________________________________-


VMS_Amoeba.xml

Description:              Based on the 2009 DiVentra’s paper 
Input models:             Vt1 is a periodic input voltage with two different frequency and base value
Memristor models:         Based on the 2009 DiVentra’s paper
Goal:                     simulating a voltage controlled memristor with threshold which is suitable for acting as synapse



-__________________________________-


Neuristor.xml

Description:              Based on the 2012 Pickett’s paper 
Input models:             Vt1 is a voltage pulse input with a super-threshold and a sub-threshold pulse Vt4 is a frequent pulse generator with fixed interval time
Memristor models:         Based on the 2012 Pickett’s paper
Goal:                     simulating a neuristor, built by Mott memristors, in sub and super threshold states


-__________________________________-


Associative.xml

Description:              Based on the 2009 Pershin’s paper 
Input models:             Vt2 and Vt5 are frequent pulse inputs for learned and unlearned neuristors, respectively
Memristor models:         M1 and M2 are related to the neuristors’ memristors and M3 ,M4 are for the synaptic voltage controlled memristors with a threshold
Goal:                     simulating an artificial neural network with two neuristor connected to a target 
		          neuristor via memristors as synapses. Memristors are in opposite states (learned 
		          and not learned or open and close), and preforming an associative learning task on 
		          the system.
