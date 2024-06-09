
import sys
sys.path.append('mnaMaker/src')
import ReadInp 
import makeMat
import PrintElem
import PrintSim
import Minion_name

class mnaMaker():

	def __init__(self, parent = None):
		
		self.Elem ={}
		self.Model={}
		self.ElemRef ={}
		self.Simu ={}
		self.NumNode = 0
		self.NumElem = 0
		self.NumG2 = 0
		self.index ={}
		self.NumNonLinElem = 0
		self.crt_name = ''
		
	ReadInput = ReadInp.ReadInput	
	MakeMatrix= makeMat.MakeMatrix
	PrintElement = PrintElem.PrintElement
	PrintSimulation = PrintSim.PrintSimulation
	MinionName = Minion_name.MinionName

