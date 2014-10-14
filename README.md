tms-robot
=========

Software for control of a robot used for transcranial magnetic stimulation experiments

RobotGUI was built in Visual C++ using VisualStudio 2013 (Ultimate Edition).
You can grab a copy of VS2013 from http://e5.onthehub.com/WebStore/ProductsByMajorVersionList.aspx?ws=b80ff89b-a18b-e011-969d-0030487d8897&vsro=8&pc=a5b2f2af-4c09-e011-bed1-0030487d8897

Notes:

--10/14/2014--
Currently, the GUI takes as input 3 coordinates and shoves them into 3 arraylists (std::vector in C++) xCoordsList,yCoordsList,zCoordsList.
Most of the code is within inputGUI.h.

There is a function execButton_Click(System::Object^  sender, System::EventArgs^  e)
at the bottom of inputGUI.h that will execute when the Execute button is clicked.
We need to make it so that  when it is clicked, the points in the coordsList arrays are transferred to the V-REP project using the remoteApi found here:
http://www.coppeliarobotics.com/helpFiles/en/remoteApiFunctions.htm
We can probably set points using the api-call simxSetObjectPosition or some shit like that, I am not sure.


Before any of this though, our main concern should be to setup some kind of Server/Client thing between the V-REP Lua and the C++ code.
The client/server setup should follow the BubbleRobClient example given by V-REP.

I don't know how you are going to work on this with a Macbook!! Visual Studio is only for Windows!! I think the computers in trottier might have VS2013 but I'm not sure...