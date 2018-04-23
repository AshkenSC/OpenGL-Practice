//
//  MtlLibrary.cpp
//
//  This file is part of the ObjLibrary, by Richard Hamilton,
//    which is copyright Hamilton 2009-2014.
//
//  This file is part of the ObjLibrary, by Richard Hamilton,
//    which is copyright Hamilton 2009-2014.
//
//  You may use these files for any purpose as long as you do
//    not explicitly claim them as your own work or object to
//    other people using them.  If you are in a position of
//    authority, you may forbid others ffrom using them in areas
//    that fall under your authority.  For example, a professor
//    could forbid students from using them for a class project,
//    or an employer could forbid employees using for a company
//    project.
//
//  If you are destributing the source files, you must not
//    remove this notice.  If you are only destributing compiled
//    code, no credit is required.
//
//  A (theoretically) up-to-date version of the ObjLibrary can
//    be found at:
//  http://infiniplix.ca/resources/obj_library/
//

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <vector>

#include "ObjStringParsing.h"
<<<<<<< HEAD
#include "ObjModel.h"  // for path propagation
=======
>>>>>>> Particles-Emitter/master
#include "Material.h"
#include "MtlLibrary.h"

using namespace std;
namespace
{
	//
<<<<<<< HEAD
	//  Are these guaranteed to be initialized before they
	//    are needed?  That would include either of:
=======
	//  Is this gaurenteed to be initialized before it is
	//    needed?  That would include either of:
>>>>>>> Particles-Emitter/master
	//    -> at compile time
	//    -> at run time, but before any function in this
	//       file is executed.
	//
<<<<<<< HEAD
	const char* DEFAULT_FILE_NAME = "unnamed.mtl";
	const char* DEFAULT_FILE_PATH = "";
=======
	const char* DEFAULT_NAME = "Unnamed";
>>>>>>> Particles-Emitter/master

	const unsigned int COLOUR_TARGET_TYPES    = 3;
	const unsigned int COLOUR_TARGET_AMBIENT  = 0;
	const unsigned int COLOUR_TARGET_DIFFUSE  = 1;
	const unsigned int COLOUR_TARGET_SPECULAR = 2;

	const unsigned int CHANNEL_TARGET_TYPES             = 5;
	const unsigned int CHANNEL_TARGET_SPECULAR_EXPONENT = 0;
	const unsigned int CHANNEL_TARGET_TRANSPARENCY      = 1;
	const unsigned int CHANNEL_TARGET_DECAL             = 2;
	const unsigned int CHANNEL_TARGET_DISPLACEMENT      = 3;
	const unsigned int CHANNEL_TARGET_BUMP              = 4;

<<<<<<< HEAD
}  // end of anonymous namespace
=======
}
>>>>>>> Particles-Emitter/master



const unsigned int MtlLibrary :: NO_SUCH_MATERIAL = ~0u;



<<<<<<< HEAD
MtlLibrary :: MtlLibrary ()
		: m_file_name(DEFAULT_FILE_NAME),
		  m_file_path(DEFAULT_FILE_PATH),
		  m_is_loaded_successfully(true),
		  mvp_materials ()
{
	makeEmpty();
=======
MtlLibrary :: MtlLibrary () : m_materials ()
{
	m_name = DEFAULT_NAME;
>>>>>>> Particles-Emitter/master

	assert(invariant());
}

MtlLibrary :: MtlLibrary (const string& filename)
<<<<<<< HEAD
		: m_file_name(DEFAULT_FILE_NAME),
		  m_file_path(DEFAULT_FILE_PATH),
		  m_is_loaded_successfully(true),
		  mvp_materials ()
{
	assert(filename.compare("") != 0);
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());

=======
{
	assert(filename.compare("") != 0);

	m_name = DEFAULT_NAME;
>>>>>>> Particles-Emitter/master
	load(filename);

	assert(invariant());
}

MtlLibrary :: MtlLibrary (const string& filename, const string& logfile)
<<<<<<< HEAD
		: m_file_name(DEFAULT_FILE_NAME),
		  m_file_path(DEFAULT_FILE_PATH),
		  m_is_loaded_successfully(true),
		  mvp_materials ()
{
	assert(filename.compare("") != 0);
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
	assert(logfile.compare("") != 0);
	assert(logfile.find_last_of("/\\") == string::npos ||
	       logfile.find_last_of("/\\") + 1 < logfile.size());

=======
{
	assert(filename.compare("") != 0);
	assert(logfile.compare("") != 0);

	m_name = DEFAULT_NAME;
>>>>>>> Particles-Emitter/master
	load(filename, logfile);

	assert(invariant());
}

MtlLibrary :: MtlLibrary (const string& filename, ostream& r_logstream)
<<<<<<< HEAD
		: m_file_name(DEFAULT_FILE_NAME),
		  m_file_path(DEFAULT_FILE_PATH),
		  m_is_loaded_successfully(true),
		  mvp_materials ()
{
	assert(filename.compare("") != 0);
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());

=======
{
	assert(filename.compare("") != 0);

	m_name = DEFAULT_NAME;
>>>>>>> Particles-Emitter/master
	load(filename, r_logstream);

	assert(invariant());
}

<<<<<<< HEAD
MtlLibrary :: MtlLibrary (const MtlLibrary& original)
		: m_file_name(original.m_file_name),
		  m_file_path(original.m_file_path),
		  m_is_loaded_successfully(original.m_is_loaded_successfully),
		  mvp_materials ()
=======
MtlLibrary :: MtlLibrary (const MtlLibrary& original) : m_materials()
>>>>>>> Particles-Emitter/master
{
	copy(original);

	assert(invariant());
}

MtlLibrary& MtlLibrary :: operator= (const MtlLibrary& original)
{
	if(&original != this)
	{
		removeAll();
<<<<<<< HEAD

		m_file_name = original.m_file_name;
		m_file_path = original.m_file_path;
		m_is_loaded_successfully = original.m_is_loaded_successfully;

=======
>>>>>>> Particles-Emitter/master
		copy(original);
	}

	assert(invariant());
	return *this;
}

MtlLibrary :: ~MtlLibrary ()
{
	removeAll();
}



<<<<<<< HEAD
const string& MtlLibrary :: getFileName () const
{
	return m_file_name;
}

const string& MtlLibrary :: getFilePath () const
{
	return m_file_path;
}

string MtlLibrary :: getFileNameWithPath () const
{
	return m_file_path + m_file_name;
}

bool MtlLibrary :: isLoadedSuccessfully () const
{
	return m_is_loaded_successfully;
}

bool MtlLibrary :: isEmpty () const
{
	return mvp_materials.empty();
=======
const string& MtlLibrary :: getName () const
{
	return m_name;
>>>>>>> Particles-Emitter/master
}

unsigned int MtlLibrary :: getMaterialCount () const
{
<<<<<<< HEAD
	return mvp_materials.size();
=======
	return m_materials.size();
>>>>>>> Particles-Emitter/master
}

bool MtlLibrary :: isMaterial (const string& name) const
{
	assert(name.compare("") != 0);

	string lower = toLowercase(name);

<<<<<<< HEAD
	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		if(mvp_materials[i]->getName().compare(lower) == 0)
=======
	for(unsigned int i = 0; i < m_materials.size(); i++)
		if(m_materials[i]->getName().compare(lower) == 0)
>>>>>>> Particles-Emitter/master
			return true;

	return false;
}

unsigned int MtlLibrary :: getMaterialIndex (const string& name) const
{
	assert(name.compare("") != 0);

	string lower = toLowercase(name);

<<<<<<< HEAD
	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		if(mvp_materials[i]->getName().compare(lower) == 0)
=======
	for(unsigned int i = 0; i < m_materials.size(); i++)
		if(m_materials[i]->getName().compare(lower) == 0)
>>>>>>> Particles-Emitter/master
			return i;

	return NO_SUCH_MATERIAL;
}

const string& MtlLibrary :: getMaterialName (unsigned int index) const
{
	assert(index < getMaterialCount());

<<<<<<< HEAD
	return mvp_materials[index]->getName();
=======
	return m_materials[index]->getName();
>>>>>>> Particles-Emitter/master
}

Material* MtlLibrary :: getMaterial (unsigned int index)
{
	assert(index < getMaterialCount());

<<<<<<< HEAD
	return mvp_materials[index];
=======
	return m_materials[index];
>>>>>>> Particles-Emitter/master
}

const Material* MtlLibrary :: getMaterial (unsigned int index) const
{
	assert(index < getMaterialCount());

<<<<<<< HEAD
	return mvp_materials[index];
=======
	return m_materials[index];
>>>>>>> Particles-Emitter/master
}

Material* MtlLibrary :: getMaterial (const string& name)
{
	assert(name.compare("") != 0);

	unsigned int index = getMaterialIndex(name);

	if(index == NO_SUCH_MATERIAL)
		return NULL;
	else
<<<<<<< HEAD
		return mvp_materials[index];
=======
		return m_materials[index];
>>>>>>> Particles-Emitter/master
}

const Material* MtlLibrary :: getMaterial (const string& name) const
{
	assert(name.compare("") != 0);

	unsigned int index = getMaterialIndex(name);

	if(index == NO_SUCH_MATERIAL)
		return NULL;
	else
<<<<<<< HEAD
		return mvp_materials[index];
=======
		return m_materials[index];
>>>>>>> Particles-Emitter/master
}

void MtlLibrary :: print () const
{
	print(cout);
}

void MtlLibrary :: print (ostream& r_outstream) const
{
<<<<<<< HEAD
	r_outstream << getFileNameWithPath() << ":" << endl;

	for(unsigned int i = 0; i < mvp_materials.size(); i++)
	{
		mvp_materials[i]->print();
=======
	r_outstream << m_name << ":" << endl;

	for(unsigned int i = 0; i < m_materials.size(); i++)
	{
		m_materials[i]->print();
>>>>>>> Particles-Emitter/master
		r_outstream << endl;
	}
}

void MtlLibrary :: save (const string& filename) const
{
	assert(filename.compare("") != 0);
<<<<<<< HEAD
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
=======
>>>>>>> Particles-Emitter/master

	save(filename, cerr);
}

void MtlLibrary :: save (const string& filename, const string& logfile) const
{
	assert(filename.compare("") != 0);
<<<<<<< HEAD
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
	assert(logfile.compare("") != 0);
	assert(logfile.find_last_of("/\\") == string::npos ||
	       logfile.find_last_of("/\\") + 1 < logfile.size());
=======
	assert(logfile.compare("") != 0);
>>>>>>> Particles-Emitter/master

	ofstream logstream;

	logstream.open(logfile.c_str());
	save(filename, logstream);
	logstream.close();
}

void MtlLibrary :: save (const string& filename, ostream& r_logstream) const
{
	assert(filename.compare("") != 0);
<<<<<<< HEAD
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
=======
>>>>>>> Particles-Emitter/master

	ofstream output_file;

	output_file.open(filename.c_str());
	if(!output_file.is_open())
	{
		r_logstream << "ERROR: cannot write to file \"" << filename << "\" - ABORTING" << endl;
		return;
	}

	//
	//  Format of file:
	//
	//  Header
	//    -> how many materials
	//  Materials
	//  Footer
	//
	//  Sections are seperated by 3 blank lines.
	//

	output_file << "#" << endl;
<<<<<<< HEAD
	output_file << "# " << getFileName() << endl;
	output_file << "#" << endl;
	output_file << "# " << getMaterialCount() << " materials" << endl;
	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		output_file << "#   " << mvp_materials[i]->getName() << endl;
=======
	output_file << "# " << getName() << endl;
	output_file << "#" << endl;
	output_file << "# " << getMaterialCount() << " materials" << endl;
	for(unsigned int i = 0; i < m_materials.size(); i++)
		output_file << "#   " << m_materials[i]->getName() << endl;
>>>>>>> Particles-Emitter/master
	output_file << "#" << endl;
	output_file << endl;
	output_file << endl;
	output_file << endl;

<<<<<<< HEAD
	for(unsigned int i2 = 0; i2 < mvp_materials.size(); i2++)
	{
		mvp_materials[i2]->save(output_file);
=======
	for(unsigned int i2 = 0; i2 < m_materials.size(); i2++)
	{
		m_materials[i2]->save(output_file);
>>>>>>> Particles-Emitter/master
		output_file << endl;
		output_file << endl;
	}

<<<<<<< HEAD
	output_file << "# End of " << getFileName() << endl;
=======
	output_file << "# End of " << getName() << endl;
>>>>>>> Particles-Emitter/master
	output_file << endl;

	output_file.close();
}



<<<<<<< HEAD
void MtlLibrary :: makeEmpty ()
{
	m_file_name = DEFAULT_FILE_NAME;
	m_file_path = DEFAULT_FILE_PATH;
	m_is_loaded_successfully = true;

	removeAll();

	assert(invariant());
}

void MtlLibrary :: load (const string& filename)
{
	assert(filename.compare("") != 0);
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
=======
void MtlLibrary :: load (const string& filename)
{
	assert(filename.compare("") != 0);
>>>>>>> Particles-Emitter/master

	load(filename, cerr);

	assert(invariant());
}

void MtlLibrary :: load (const string& filename, const string& logfile)
{
	assert(filename.compare("") != 0);
<<<<<<< HEAD
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
	assert(logfile.compare("") != 0);
	assert(logfile.find_last_of("/\\") == string::npos ||
	       logfile.find_last_of("/\\") + 1 < logfile.size());
=======
	assert(logfile.compare("") != 0);
>>>>>>> Particles-Emitter/master

	ofstream logstream;

	logstream.open(logfile.c_str());
	load(filename, logstream);
	logstream.close();

	assert(invariant());
}

void MtlLibrary :: load (const string& filename, ostream& r_logstream)
{
	assert(filename.compare("") != 0);
<<<<<<< HEAD
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());
=======
>>>>>>> Particles-Emitter/master

	ifstream input_file;
	unsigned int line_count;

	removeAll();

<<<<<<< HEAD
	m_is_loaded_successfully = true;
	setFileNameWithPath(filename);

=======
	m_name = toLowercase(filename);
>>>>>>> Particles-Emitter/master
	input_file.open(filename.c_str());
	if(!input_file.is_open())
	{
		r_logstream << "Error: File \"" << filename << "\" does not exist" << endl;
		input_file.close();
<<<<<<< HEAD
		m_is_loaded_successfully = false;
=======
>>>>>>> Particles-Emitter/master

		assert(invariant());
		return;
	}

	//
	//  Format is available at
	//
	//  http://paulbourke.net/dataformats/mtl/
	//

	line_count = 0;
	while(true)	// drops out at EOF below
	{
		string line;
		size_t length;
		bool valid;

		getline(input_file, line);
		if(input_file.eof())
			break;	// drop out after last line

		length = line.length();
		line_count++;

		if(length < 1 || line[0] == '#' || line[0] == '\r')
			continue;	// skip blank lines and comments

		if(isspace(line[0]))
			line = line.substr(nextToken(line, 0));

		valid = true;
		if(length < 3)
			valid = false;
		else
		{
			if(line.length() >= 7 && line.substr(0, 6).compare("newmtl") == 0 && isspace(line[6]))
				valid = readMaterialStart(line.substr(7), r_logstream);
			else if(line.length() >= 6 && line.substr(0, 5).compare("illum") == 0 && isspace(line[5]))
				valid = readIlluminationMode(line.substr(6), r_logstream);
			else if(line[0] == 'K' && line[1] == 'a' && isspace(line[2]))
				valid = readColour(line.substr(3), COLOUR_TARGET_AMBIENT, r_logstream);
			else if(line[0] == 'K' && line[1] == 'd' && isspace(line[2]))
				valid = readColour(line.substr(3), COLOUR_TARGET_DIFFUSE, r_logstream);
			else if(line[0] == 'K' && line[1] == 's' && isspace(line[2]))
				valid = readColour(line.substr(3), COLOUR_TARGET_SPECULAR, r_logstream);
			else if(line[0] == 'N' && line[1] == 's' && isspace(line[2]))
				valid = readSpecularExponent(line.substr(3), r_logstream);
			else if(line[0] == 'd' && isspace(line[1]))
				valid = readTransparency(line.substr(2), r_logstream);
			else if(line[0] == 'T' && line[1] == 'r' && isspace(line[2]))
				valid = readTransparency(line.substr(3), r_logstream);
			else if(line[0] == 'N' && line[1] == 'i' && isspace(line[2]))
				valid = readOpticalDensity(line.substr(3), r_logstream);
			else if(line[0] == 'T' && line[1] == 'f' && isspace(line[2]))
				valid = readTransmissionFilter(line.substr(3), r_logstream);
			else if(line.length() >= 7 && line.substr(0, 6).compare("map_Ka") == 0 && isspace(line[6]))
				valid = readMapColour(line.substr(7), COLOUR_TARGET_AMBIENT, r_logstream);
			else if(line.length() >= 7 && line.substr(0, 6).compare("map_Kd") == 0 && isspace(line[6]))
				valid = readMapColour(line.substr(7), COLOUR_TARGET_DIFFUSE, r_logstream);
			else if(line.length() >= 7 && line.substr(0, 6).compare("map_Ks") == 0 && isspace(line[6]))
				valid = readMapColour(line.substr(7), COLOUR_TARGET_SPECULAR, r_logstream);
			else if(line.length() >= 7 && line.substr(0, 6).compare("map_Ns") == 0 && isspace(line[6]))
				valid = readMapChannel(line.substr(7), CHANNEL_TARGET_SPECULAR_EXPONENT, r_logstream);
			else if(line.length() >= 7 && line.substr(0, 6).compare("map_Ns") == 0 && isspace(line[6]))
				valid = readMapChannel(line.substr(7), CHANNEL_TARGET_SPECULAR_EXPONENT, r_logstream);
			else if(line.length() >= 6 && line.substr(0, 5).compare("map_d") == 0 && isspace(line[5]))
				valid = readMapChannel(line.substr(6), CHANNEL_TARGET_TRANSPARENCY, r_logstream);
			else if(line.length() >= 7 && line.substr(0, 6).compare("map_Tr") == 0 && isspace(line[6]))
				valid = readMapChannel(line.substr(7), CHANNEL_TARGET_TRANSPARENCY, r_logstream);
			else if(line.length() >= 6 && line.substr(0, 5).compare("decal") == 0 && isspace(line[5]))
				valid = readMapChannel(line.substr(6), CHANNEL_TARGET_DECAL, r_logstream);
			else if(line.length() >= 5 && line.substr(0, 4).compare("disp") == 0 && isspace(line[4]))
				valid = readMapChannel(line.substr(5), CHANNEL_TARGET_DISPLACEMENT, r_logstream);
			else if(line.length() >= 5 && line.substr(0, 4).compare("bump") == 0 && isspace(line[4]))
				valid = readMapChannel(line.substr(5), CHANNEL_TARGET_BUMP, r_logstream);
			else if(line[0] == 'K' && line[1] == 'm' && isspace(line[2]))	// non-standard - is this what it does?
				valid = readBumpMapMultiplier(line.substr(3), r_logstream);
			else
				valid = false;
		}

		if(!valid)
			r_logstream << "Line " << setw(6) << line_count << " of file \"" << filename << "\" is invalid: \"" << line << "\"" << endl;
	}

	warnIfLastMaterialIsInvisible(r_logstream);
	input_file.close();

	assert(invariant());
}

<<<<<<< HEAD
void MtlLibrary :: setFileName (const string& file_name)
{
	assert(file_name.compare("") != 0);

	m_file_name = toLowercase(file_name);

	assert(invariant());
}

void MtlLibrary :: setFilePath (const string& file_path)
{
	m_file_path = toLowercase(file_path);

	assert(invariant());
}

void MtlLibrary :: setFileNameWithPath (const string& filename)
{
	assert(filename.compare("") != 0);
	assert(filename.find_last_of("/\\") == string::npos ||
	       filename.find_last_of("/\\") + 1 < filename.size());

	string lowercase = toLowercase(filename);

	size_t last_slash = lowercase.find_last_of("/\\");
	if(last_slash != string::npos)
	{
		last_slash++;
		m_file_name = lowercase.substr(last_slash);
		m_file_path = lowercase.substr(0, last_slash);
	}
	else
	{
		m_file_name = lowercase;
		m_file_path = "";
	}
=======
void MtlLibrary :: setName (const string& name)
{
	assert(name.compare("") != 0);

	m_name = toLowercase(name);
>>>>>>> Particles-Emitter/master

	assert(invariant());
}

unsigned int MtlLibrary :: add (Material* p_material)
{
	assert(p_material != NULL);
	assert(!isMaterial(p_material->getName()));

<<<<<<< HEAD
	unsigned int index = mvp_materials.size();
	mvp_materials.push_back(p_material);
=======
	unsigned int index = m_materials.size();
	m_materials.push_back(p_material);
>>>>>>> Particles-Emitter/master

	assert(invariant());
	return index;
}

void MtlLibrary :: removeAll ()
{
<<<<<<< HEAD
	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		delete mvp_materials[i];
	mvp_materials.clear();

	assert(mvp_materials.size() == 0);
=======
	for(unsigned int i = 0; i < m_materials.size(); i++)
		delete m_materials[i];
	m_materials.clear();

	assert(m_materials.size() == 0);
>>>>>>> Particles-Emitter/master
	assert(invariant());
}

void MtlLibrary :: loadDisplayTextures ()
{
<<<<<<< HEAD
	string propagated_path;
	if(ObjModel::isPathPropagation())
		propagated_path = m_file_path;

	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		mvp_materials[i]->loadDisplayTextures(propagated_path);
=======
	for(unsigned int i = 0; i < m_materials.size(); i++)
		m_materials[i]->loadDisplayTextures();
>>>>>>> Particles-Emitter/master

	assert(invariant());
}

void MtlLibrary :: loadAllTextures ()
{
<<<<<<< HEAD
	string propagated_path;
	if(ObjModel::isPathPropagation())
		propagated_path = m_file_path;

	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		mvp_materials[i]->loadAllTextures(propagated_path);
=======
	for(unsigned int i = 0; i < m_materials.size(); i++)
		m_materials[i]->loadAllTextures();
>>>>>>> Particles-Emitter/master

	assert(invariant());
}



void MtlLibrary :: warnIfLastMaterialIsInvisible (ostream& r_outstream) const
{
<<<<<<< HEAD
	if(mvp_materials.empty())
=======
	if(m_materials.empty())
>>>>>>> Particles-Emitter/master
		return;

	unsigned int current_material;

<<<<<<< HEAD
	assert(mvp_materials.size() >= 1);
	current_material = mvp_materials.size() - 1;
	if(mvp_materials[current_material]->getTransparency() == 0.0)
	{
		r_outstream << "Material " << mvp_materials[current_material]->getName()
		            << " in file " << getFileNameWithPath() << " is entirely transprent" << endl;
	}
=======
	assert(m_materials.size() >= 1);
	current_material = m_materials.size() - 1;
	if(m_materials[current_material]->getTransparency() == 0.0)
		r_outstream << "Material " << m_materials[current_material]->getName() << " in file " << m_name << " is entirely transprent" << endl;
>>>>>>> Particles-Emitter/master
}

bool MtlLibrary :: readMaterialStart (const string& str, ostream& r_logstream)
{
	size_t start;
	size_t length;
	string name;

	warnIfLastMaterialIsInvisible(r_logstream);

	if(isspace(str[0]))
		start = nextToken(str, 0);
	else
		start = 0;

	length = getTokenLength(str, start);
	name = str.substr(start, length);

	if(name.compare("") == 0 || isMaterial(name))
		return false;

	add(new Material(toLowercase(name)));
	return true;
}

bool MtlLibrary :: readIlluminationMode (const string& str, ostream& r_logstream)
{
	size_t index;

	unsigned int illumination_mode;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	switch(atoi(str.c_str() + index))
	{
	case 0: illumination_mode = Material::ILLUMINATION_CONSTANT; break;
	case 1: illumination_mode = Material::ILLUMINATION_PHONG_NO_SPECULAR; break;
	case 2: illumination_mode = Material::ILLUMINATION_PHONG; break;
	case 3: illumination_mode = Material::ILLUMINATION_RAY_REFLECTIVE; break;
	case 4: illumination_mode = Material::ILLUMINATION_RAY_GLASS; break;
	case 5: illumination_mode = Material::ILLUMINATION_RAY_FRESNEL; break;
	case 6: illumination_mode = Material::ILLUMINATION_RAY_REFRACTION; break;
	case 7: illumination_mode = Material::ILLUMINATION_RAY_FRESNEL_REFRACTION; break;
	case 8: illumination_mode = Material::ILLUMINATION_REFLECTIVE; break;
	case 9: illumination_mode = Material::ILLUMINATION_GLASS; break;
	case 10: illumination_mode = Material::ILLUMINATION_RAY_INVISIBLE_SHADOWS; break;
	default: return false;
	}

<<<<<<< HEAD
	mvp_materials[current_material]->setIlluminationMode(illumination_mode);
=======
	m_materials[current_material]->setIlluminationMode(illumination_mode);
>>>>>>> Particles-Emitter/master
	return true;
}

bool MtlLibrary :: readColour (const string& str, unsigned int target, ostream& r_logstream)
{
	assert(target < COLOUR_TARGET_TYPES);

	double red;
	double green;
	double blue;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	red = atof(str.c_str() + index);

	index = nextToken(str, index);
	if(index == string::npos)
	{
		//  Providing only one value for a colour is legal.
		//    Greyscale is assumed.

		switch(target)
		{
		case COLOUR_TARGET_AMBIENT:
<<<<<<< HEAD
			mvp_materials[current_material]->setAmbientColour(red, red, red);
			break;
		case COLOUR_TARGET_DIFFUSE:
			mvp_materials[current_material]->setDiffuseColour(red, red, red);
			break;
		case COLOUR_TARGET_SPECULAR:
			mvp_materials[current_material]->setSpecularColour(red, red, red);
=======
			m_materials[current_material]->setAmbientColour(red, red, red);
			break;
		case COLOUR_TARGET_DIFFUSE:
			m_materials[current_material]->setDiffuseColour(red, red, red);
			break;
		case COLOUR_TARGET_SPECULAR:
			m_materials[current_material]->setSpecularColour(red, red, red);
>>>>>>> Particles-Emitter/master
			break;
		}

		return true;
	}

	green = atof(str.c_str() + index);

	index = nextToken(str, index);
	if(index == string::npos)
		return false;

	blue = atof(str.c_str() + index);

	switch(target)
	{
	case COLOUR_TARGET_AMBIENT:
<<<<<<< HEAD
		mvp_materials[current_material]->setAmbientColour(red, green, blue);
		break;
	case COLOUR_TARGET_DIFFUSE:
		mvp_materials[current_material]->setDiffuseColour(red, green, blue);
		break;
	case COLOUR_TARGET_SPECULAR:
		mvp_materials[current_material]->setSpecularColour(red, green, blue);
=======
		m_materials[current_material]->setAmbientColour(red, green, blue);
		break;
	case COLOUR_TARGET_DIFFUSE:
		m_materials[current_material]->setDiffuseColour(red, green, blue);
		break;
	case COLOUR_TARGET_SPECULAR:
		m_materials[current_material]->setSpecularColour(red, green, blue);
>>>>>>> Particles-Emitter/master
		break;
	}

	return true;
}

bool MtlLibrary :: readSpecularExponent (const string& str, ostream& r_logstream)
{
	double exponent;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	exponent = atof(str.c_str() + index);

<<<<<<< HEAD
	mvp_materials[current_material]->setSpecularExponent(exponent);
=======
	m_materials[current_material]->setSpecularExponent(exponent);
>>>>>>> Particles-Emitter/master
	return true;
}

bool MtlLibrary :: readTransparency (const string& str, ostream& r_logstream)
{
	double transparency;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	transparency = atof(str.c_str() + index);
	if(transparency < 0.0)
		return false;
	if(transparency > 1.0)
		return false;

<<<<<<< HEAD
	mvp_materials[current_material]->setTransparency(transparency);
=======
	m_materials[current_material]->setTransparency(transparency);
>>>>>>> Particles-Emitter/master
	return true;
}

bool MtlLibrary :: readOpticalDensity (const std::string& str, std::ostream& r_logstream)
{
	double optical_density;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	optical_density = atof(str.c_str() + index);

<<<<<<< HEAD
	mvp_materials[current_material]->setOpticalDensity(optical_density);
=======
	m_materials[current_material]->setOpticalDensity(optical_density);
>>>>>>> Particles-Emitter/master
	return true;
}

bool MtlLibrary :: readTransmissionFilter (const string& str, ostream& r_logstream)
{
	double red;
	double green;
	double blue;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	red = atof(str.c_str() + index);

	index = nextToken(str, index);
	if(index == string::npos)
	{
		//  Providing only one value for a colour is legal.
		//    Greyscale is assumed.

<<<<<<< HEAD
		mvp_materials[current_material]->setTransmissionFilter(red, red, red);
=======
		m_materials[current_material]->setTransmissionFilter(red, red, red);
>>>>>>> Particles-Emitter/master
		return true;
	}

	green = atof(str.c_str() + index);

	index = nextToken(str, index);
	if(index == string::npos)
		return false;

	blue = atof(str.c_str() + index);

<<<<<<< HEAD
	mvp_materials[current_material]->setTransmissionFilter(red, green, blue);
=======
	m_materials[current_material]->setTransmissionFilter(red, green, blue);
>>>>>>> Particles-Emitter/master
	return true;
}

bool MtlLibrary :: readBumpMapMultiplier (const std::string& str, std::ostream& r_logstream)
{
	double multiplier;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	multiplier = atof(str.c_str() + index);

<<<<<<< HEAD
	mvp_materials[current_material]->setBumpMapMultiplier(multiplier);
=======
	m_materials[current_material]->setBumpMapMultiplier(multiplier);
>>>>>>> Particles-Emitter/master
	return true;
}



bool MtlLibrary :: readMapColour (const string& str, unsigned int target, ostream& r_logstream)
{
	assert(target < COLOUR_TARGET_TYPES);

	string filename;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	filename = str.substr(index, getTokenLength(str, index));
	if(filename.compare("") == 0 || isMaterial(filename))
		return false;

	switch(target)
	{
	case COLOUR_TARGET_AMBIENT:
<<<<<<< HEAD
		mvp_materials[current_material]->setAmbientMap(filename);
		break;
	case COLOUR_TARGET_DIFFUSE:
		mvp_materials[current_material]->setDiffuseMap(filename);
		break;
	case COLOUR_TARGET_SPECULAR:
		mvp_materials[current_material]->setSpecularMap(filename);
=======
		m_materials[current_material]->setAmbientMap(filename);
		break;
	case COLOUR_TARGET_DIFFUSE:
		m_materials[current_material]->setDiffuseMap(filename);
		break;
	case COLOUR_TARGET_SPECULAR:
		m_materials[current_material]->setSpecularMap(filename);
>>>>>>> Particles-Emitter/master
		break;
	}

	return true;
}

bool MtlLibrary :: readMapChannel (const string& str, unsigned int target, ostream& r_logstream)
{
	assert(target < CHANNEL_TARGET_TYPES);

	string filename;
	unsigned char channel;
	double bump_multiplier = 1.0;

	size_t index;
	unsigned int current_material;

<<<<<<< HEAD
	current_material = mvp_materials.size() - 1;
=======
	current_material = m_materials.size() - 1;
>>>>>>> Particles-Emitter/master

	if(target == CHANNEL_TARGET_DECAL)
		channel = Material::CHANNEL_MATTE;
	else
		channel = Material::CHANNEL_LUMINANCE;

	if(isspace(str[0]))
		index = nextToken(str, 0);
	else
		index = 0;

	filename = str.substr(index, getTokenLength(str, index));
	if(filename.compare("") == 0 || isMaterial(filename))
		return false;

	index = nextToken(str, index);
	while(index != string::npos)
	{
		string token;

		token = str.substr(index, getTokenLength(str, index));
		if(token.compare("-imfchan") == 0)
		{
			index = nextToken(str, index);
			if(index == string::npos)
				return false;

			token = str.substr(index, getTokenLength(str, index));
			if(token.compare("r") == 0)
				channel = Material::CHANNEL_RED;
			else if(token.compare("g") == 0)
				channel = Material::CHANNEL_GREEN;
			else if(token.compare("b") == 0)
				channel = Material::CHANNEL_BLUE;
			else if(token.compare("m") == 0)
				channel = Material::CHANNEL_MATTE;
			else if(token.compare("l") == 0)
				channel = Material::CHANNEL_LUMINANCE;
			else if(token.compare("z") == 0)
				channel = Material::CHANNEL_Z_DEPTH;
			else
				return false;
		}
		else if(token.compare("-bm") == 0)
		{
			if(channel != CHANNEL_TARGET_BUMP)
				return false;

			index = nextToken(str, index);
			if(index == string::npos)
				return false;

			bump_multiplier = atof(str.c_str() + index);
		}

		index = nextToken(str, index);
	}

	switch(target)
	{
	case CHANNEL_TARGET_SPECULAR_EXPONENT:
<<<<<<< HEAD
		mvp_materials[current_material]->setSpecularExponentMap(filename, channel);
		break;
	case CHANNEL_TARGET_TRANSPARENCY:
		mvp_materials[current_material]->setTransparencyMap(filename, channel);
		break;
	case CHANNEL_TARGET_DECAL:
		mvp_materials[current_material]->setDecalMap(filename, channel);
		break;
	case CHANNEL_TARGET_DISPLACEMENT:
		mvp_materials[current_material]->setDisplacementMap(filename, channel);
		break;
	case CHANNEL_TARGET_BUMP:
		mvp_materials[current_material]->setBumpMap(filename, channel, bump_multiplier);
=======
		m_materials[current_material]->setSpecularExponentMap(filename, channel);
		break;
	case CHANNEL_TARGET_TRANSPARENCY:
		m_materials[current_material]->setTransparencyMap(filename, channel);
		break;
	case CHANNEL_TARGET_DECAL:
		m_materials[current_material]->setDecalMap(filename, channel);
		break;
	case CHANNEL_TARGET_DISPLACEMENT:
		m_materials[current_material]->setDisplacementMap(filename, channel);
		break;
	case CHANNEL_TARGET_BUMP:
		m_materials[current_material]->setBumpMap(filename, channel, bump_multiplier);
>>>>>>> Particles-Emitter/master
		break;
	}

	return true;
}

void MtlLibrary :: copy (const MtlLibrary& original)
{
<<<<<<< HEAD
	assert(mvp_materials.size() == 0);

	unsigned int material_count = original.mvp_materials.size();
	mvp_materials.resize(material_count);
	for(unsigned int i = 0; i < material_count; i++)
	{
		assert(i < mvp_materials.size());
		assert(i < original.mvp_materials.size());
		assert(original.mvp_materials[i] != NULL);
		mvp_materials[i] = new Material(*(original.mvp_materials[i]));
=======
	assert(m_materials.size() == 0);

	unsigned int material_count = original.m_materials.size();

	m_name = original.m_name;
	m_materials.resize(material_count);
	for(unsigned int i = 0; i < material_count; i++)
	{
		assert(i < m_materials.size());
		assert(i < original.m_materials.size());
		assert(original.m_materials[i] != NULL);
		m_materials[i] = new Material(*(original.m_materials[i]));
>>>>>>> Particles-Emitter/master
	}

	assert(invariant());
}

bool MtlLibrary :: invariant () const
{
<<<<<<< HEAD
	if(m_file_name.compare("") == 0) return false;

	for(unsigned int i = 0; i < mvp_materials.size(); i++)
		if(mvp_materials[i] == NULL)
=======
	if(m_name.compare("") == 0) return false;

	for(unsigned int i = 0; i < m_materials.size(); i++)
		if(m_materials[i] == NULL)
>>>>>>> Particles-Emitter/master
			return false;

	return true;
}