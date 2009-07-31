
TEMPLATE      = lib
CONFIG       += plugin debug_and_release

INCLUDEPATH += 	. \
				src \
				$$(TONATIUH_ROOT)/src \
				$$(TDE_ROOT)/local/include

win32 {
	DEFINES+= COIN_DLL SOQT_DLL
}

# Input
HEADERS = *.h \ 
			$$(TONATIUH_ROOT)/src/BBox.h \
           	$$(TONATIUH_ROOT)/src/DifferentialGeometry.h \
 			$$(TONATIUH_ROOT)/src/InstanceNode.h \
           	$$(TONATIUH_ROOT)/src/Matrix4x4.h \
           	$$(TONATIUH_ROOT)/src/NormalVector.h \
           	$$(TONATIUH_ROOT)/src/Photon.h \
           	$$(TONATIUH_ROOT)/src/Point3D.h \
           	$$(TONATIUH_ROOT)/src/Ray.h \
           	$$(TONATIUH_ROOT)/src/RefCount.h \
           	$$(TONATIUH_ROOT)/src/tgf.h \
           	$$(TONATIUH_ROOT)/src/TMaterial.h \
           	$$(TONATIUH_ROOT)/src/Trace.h  \
           	$$(TONATIUH_ROOT)/src/Transform.h \
           	$$(TONATIUH_ROOT)/src/TShape.h \ 
           	$$(TONATIUH_ROOT)/src/TShapeKit.h \
           	$$(TONATIUH_ROOT)/src/Vector3D.h

SOURCES = *.cpp  \ 
			$$(TONATIUH_ROOT)/src/BBox.cpp \
           	$$(TONATIUH_ROOT)/src/DifferentialGeometry.cpp \
 			$$(TONATIUH_ROOT)/src/InstanceNode.cpp \
           	$$(TONATIUH_ROOT)/src/Matrix4x4.cpp \
           	$$(TONATIUH_ROOT)/src/NormalVector.cpp \ 
           	$$(TONATIUH_ROOT)/src/Photon.cpp \
           	$$(TONATIUH_ROOT)/src/Point3D.cpp \
           	$$(TONATIUH_ROOT)/src/Ray.cpp \
           	$$(TONATIUH_ROOT)/src/RefCount.cpp \
           	$$(TONATIUH_ROOT)/src/tgf.cpp \
           	$$(TONATIUH_ROOT)/src/TMaterial.cpp \
           	$$(TONATIUH_ROOT)/src/Trace.cpp  \
           	$$(TONATIUH_ROOT)/src/Transform.cpp \
           	$$(TONATIUH_ROOT)/src/TShape.cpp \ 
           	$$(TONATIUH_ROOT)/src/TShapeKit.cpp \
           	$$(TONATIUH_ROOT)/src/Vector3D.cpp
           	
RESOURCES += ShapeFlatDisk.qrc		
TARGET        = ShapeFlatDisk

contains(TEMPLATE,lib) {  
	CONFIG(debug, debug|release) {
		DESTDIR       = $$(TONATIUH_ROOT)/bin/debug/plugins/ShapeFlatDisk	
		unix {
			LIBS +=-L$$(TDE_ROOT)/local/lib -lCoin_debug -lSoQt_debug
			TARGET = $$member(TARGET, 0)_debug
		}
		else {
			LIBS +=-L$$(TDE_ROOT)/local/lib -lCoind -lSoQtd
			TARGET = $$member(TARGET, 0)d
		}
	}
	else { 
		LIBS +=-L$$(TDE_ROOT)/local/lib -lCoin -lSoQt
		DESTDIR       = $$(TONATIUH_ROOT)/bin/release/plugins/ShapeFlatDisk
	}
}
