# CerberusMikMod
MikMod integration for Cerberus-X (GLFW target) https://www.cerberus-x.com

# Test

Cerberus-X test code:

``` monkey
Import mikmod
Import mojo
 
Function Main()
    New TestMikmod()
End Function
 
Class TestMikmod Extends App
 
    Method OnCreate()
        MikmodInit()
        MikmodPlay("data/featsov.xm")
    End Method
 
    Method OnUpdate()
 
        If KeyHit(KEY_SPACE)
            MikmodPause()
        Endif
        If KeyHit(KEY_ESCAPE)
            MikmodStop()
        Endif
 
        MikmodUpdate()
     
    End Method
 
    Method OnRender()
        Cls 255,255,255
    End Method
 
    Method OnClose()
        MikmodQuit()
        EndApp()
    End Method  
 
End Class

```