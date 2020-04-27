idf_component_register(SRCS "DjembeGroove.cpp"
                       INCLUDE_DIRS "include"                       # Edit following two lines to set component requirements (see docs)
                       REQUIRES jdksmidi
                       PRIV_REQUIRES )
                       
set_source_files_properties(DjembeGroove.cpp
    			    PROPERTIES COMPILE_FLAGS
        		    -frtti )               
