TEMPLATE      = lib
CONFIG       += plugin debug_and_release

include( ../../config.pri )

INCLUDEPATH += 	. \
				src \
				$$(TONATIUH_ROOT)/src \

# Input
HEADERS = src/*.h \
            $$(TONATIUH_ROOT)/src/source/geometry/BBox.h \
            $$(TONATIUH_ROOT)/src/source/geometry/Matrix4x4.h \
            $$(TONATIUH_ROOT)/src/source/geometry/NormalVector.h \
            $$(TONATIUH_ROOT)/src/source/geometry/Point3D.h \
            $$(TONATIUH_ROOT)/src/source/geometry/RefCount.h \
            $$(TONATIUH_ROOT)/src/source/geometry/tgf.h \
            $$(TONATIUH_ROOT)/src/source/geometry/Transform.h \
            $$(TONATIUH_ROOT)/src/source/geometry/Vector3D.h \
            $$(TONATIUH_ROOT)/src/source/raytracing/trt.h \
            $$(TONATIUH_ROOT)/src/source/raytracing/TSceneKit.h \
            $$(TONATIUH_ROOT)/src/source/raytracing/TTracker.h \
            $$(TONATIUH_ROOT)/src/source/raytracing/TTrackerFactory.h


SOURCES = src/*.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/BBox.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/Matrix4x4.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/NormalVector.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/Point3D.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/RefCount.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/tgf.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/Transform.cpp \
            $$(TONATIUH_ROOT)/src/source/geometry/Vector3D.cpp \
            $$(TONATIUH_ROOT)/src/source/raytracing/TSceneKit.cpp \
            $$(TONATIUH_ROOT)/src/source/raytracing/TTracker.cpp

RESOURCES += src/TrackerOneAxis.qrc
TARGET        = TrackerOneAxis

CONFIG(debug, debug|release) {
	DESTDIR       = $$(TONATIUH_ROOT)/bin/debug/plugins/TrackerOneAxis	
}
else { 
	DESTDIR       = $$(TONATIUH_ROOT)/bin/release/plugins/TrackerOneAxis
}
