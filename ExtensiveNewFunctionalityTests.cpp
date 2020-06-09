/*

Extensive tests for the new cv::FileStorage copy constructor
and assignment operator

Uses opencv_extra's io folder

*/
#include<assert.h>
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/core/persistence.hpp>

int main(int argc, char* argv[])
{
	// File path to XML/YAML/JSON files provided in opencv_extra's io folder
	std::string test_xml = "";
	std::string test_yml = "";
	std::string test_json = "";

	cv::FileStorage org_xml_fs(test_xml, cv::FileStorage::READ);
	cv::FileStorage org_yml_fs(test_yml, cv::FileStorage::READ);
	cv::FileStorage org_json_fs(test_json, cv::FileStorage::READ);

	cv::Mat xml_2d_mat;
	cv::Mat yml_2d_mat;
	cv::Mat json_2d_mat;

	org_xml_fs["normal_2d_mat"] >> xml_2d_mat;
	org_yml_fs["normal_2d_mat"] >> yml_2d_mat;
	org_json_fs["normal_2d_mat"] >> json_2d_mat;

	std::cout << "##### Checking to see if cv::FileStorage can still open XML/YAML/JSON files #####" << std::endl;
	// Checks to see if FileStorage can still open XML/YAML/JSON files
	{
		assert(org_xml_fs.isOpened());
		/*if (org_xml_fs.isOpened())
		{
			std::cout << "XML is open" << std::endl;
		}
		else
		{
			std::cout << "XML file did not open" << std::endl;
			return -1;
		}*/
		
		assert(org_yml_fs.isOpened());
		/*if (org_yml_fs.isOpened())
		{
			std::cout << "YAML is open" << std::endl;
		}
		else
		{
			std::cout << "YAML file did not open" << std::endl;
			return -1;
		}*/

		assert(org_json_fs.isOpened());
		/*if (org_json_fs.isOpened())
		{
			std::cout << "JSON is open" << std::endl;
		}
		else
		{
			std::cout << "JSON file did not open" << std::endl;
			return -1;
		}*/
	}
	std::cout << std::endl;

	std::cout << "##### Conducting copy constructor tests #####" << std::endl;
	// ***** Copy Constructor Tests ***** //
	{
		cv::FileStorage xml_fs_copy(org_xml_fs);
		cv::FileStorage yml_fs_copy(org_yml_fs);
		cv::FileStorage json_fs_copy(org_json_fs);

		// See if the cv::FileStorage copies are opened
		{
			assert(xml_fs_copy.isOpened());
			/*if (xml_fs_copy.isOpened())
			{
				std::cout << "Copy of XML is open" << std::endl;
			}
			else
			{
				std::cout << "Copy of XML file did not open" << std::endl;
				return -1;
			}*/

			assert(yml_fs_copy.isOpened());
			/*if (yml_fs_copy.isOpened())
			{
				std::cout << "Copy of YAML is open" << std::endl;
			}
			else
			{
				std::cout << "Copy of YAML file did not open" << std::endl;
				return -1;
			}*/

			assert(json_fs_copy.isOpened());
			/*if (json_fs_copy.isOpened())
			{
				std::cout << "Copy of JSON is open" << std::endl;
			}
			else
			{
				std::cout << "Copy of JSON file did not open" << std::endl;
				return -1;
			}*/
		}

		// See if at least the 2D matrix in the cv::FileStorage objects can be read
		// and if they are the same
		{
			cv::Mat copy_xml_2d_mat;
			cv::Mat copy_yml_2d_mat;
			cv::Mat copy_json_2d_mat;
			bool eq = false;

			xml_fs_copy["normal_2d_mat"] >> copy_xml_2d_mat;
			yml_fs_copy["normal_2d_mat"] >> copy_yml_2d_mat;
			json_fs_copy["normal_2d_mat"] >> copy_json_2d_mat;

			// Does the XML copy have the same matrix as the original?
			eq = (cv::sum(xml_2d_mat != copy_xml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied XML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied XML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the YAML copy have the same matrix as the original?
			eq = (cv::sum(yml_2d_mat != copy_yml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied YAML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied YAML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the JSON copy have the same matrix as the original?
			eq = (cv::sum(json_2d_mat != copy_json_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied JSON FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied JSON FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/
		}
	}
	std::cout << std::endl;

	std::cout << "##### Conducting assignment operator tests #####" << std::endl;
	// ***** Assignment Operator Tests ***** //
	{
		cv::FileStorage xml_fs_assign;
		cv::FileStorage yml_fs_assign;
		cv::FileStorage json_fs_assign;

		xml_fs_assign = org_xml_fs;
		yml_fs_assign = org_yml_fs;
		json_fs_assign = org_json_fs;

		// See if the assigned cv::FileStorage objects are opened
		{
			assert(xml_fs_assign.isOpened());
			/*if (xml_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for XML file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for XML file did not open" << std::endl;
				return -1;
			}*/

			assert(yml_fs_assign.isOpened());
			/*if (yml_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for YAML file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for YAML file did not open" << std::endl;
				return -1;
			}*/

			assert(json_fs_assign.isOpened());
			/*if (json_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for JSON file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for JSON file did not open" << std::endl;
				return -1;
			}*/
		}

		// See if at least the 2D matrix in the cv::FileStorage objects can be read
		// and if they are the same
		{
			cv::Mat assigned_xml_2d_mat;
			cv::Mat assigned_yml_2d_mat;
			cv::Mat assigned_json_2d_mat;
			bool eq = false;

			xml_fs_assign["normal_2d_mat"] >> assigned_xml_2d_mat;
			yml_fs_assign["normal_2d_mat"] >> assigned_yml_2d_mat;
			json_fs_assign["normal_2d_mat"] >> assigned_json_2d_mat;

			// Does the XML copy have the same matrix as the original?
			eq = (cv::sum(xml_2d_mat != assigned_xml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied XML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied XML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the YAML copy have the same matrix as the original?
			eq = (cv::sum(yml_2d_mat != assigned_yml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied YAML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied YAML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the JSON copy have the same matrix as the original?
			eq = (cv::sum(json_2d_mat != assigned_json_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied JSON FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied JSON FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/
		}
	}
	std::cout << std::endl;

	std::cout << "##### Conducting assignment operator with temporary objects (using copy constructor) tests (see Issue #17412) #####" << std::endl;
	// ***** Assignment Operator with Temporary Object (using copy constructor) Tests ***** //
	{
		cv::FileStorage xml_fs_assign = cv::FileStorage(org_xml_fs);
		cv::FileStorage yml_fs_assign = cv::FileStorage(org_yml_fs);
		cv::FileStorage json_fs_assign = cv::FileStorage(org_json_fs);

		// See if the assigned cv::FileStorage objects are opened
		{
			assert(xml_fs_assign.isOpened());
			/*if (xml_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for XML file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for XML file did not open" << std::endl;
				return -1;
			}*/

			assert(yml_fs_assign.isOpened());
			/*if (yml_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for YAML file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for YAML file did not open" << std::endl;
				return -1;
			}*/

			assert(json_fs_assign.isOpened());
			/*if (json_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for JSON file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for JSON file did not open" << std::endl;
				return -1;
			}*/
		}

		// See if at least the 2D matrix in the cv::FileStorage objects can be read
		// and if they are the same
		{
			cv::Mat assigned_xml_2d_mat;
			cv::Mat assigned_yml_2d_mat;
			cv::Mat assigned_json_2d_mat;
			bool eq = false;

			xml_fs_assign["normal_2d_mat"] >> assigned_xml_2d_mat;
			yml_fs_assign["normal_2d_mat"] >> assigned_yml_2d_mat;
			json_fs_assign["normal_2d_mat"] >> assigned_json_2d_mat;

			// Does the XML copy have the same matrix as the original?
			eq = (cv::sum(xml_2d_mat != assigned_xml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied XML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied XML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the YAML copy have the same matrix as the original?
			eq = (cv::sum(yml_2d_mat != assigned_yml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied YAML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied YAML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the JSON copy have the same matrix as the original?
			eq = (cv::sum(json_2d_mat != assigned_json_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied JSON FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied JSON FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/
		}
	}
	std::cout << std::endl;

	std::cout << "##### Conducting assignment operator with temporary objects tests (see Issue #17412) #####" << std::endl;
	// ***** Assignment Operator with Temporary Object Tests ***** //
	{
		cv::FileStorage xml_fs_assign = cv::FileStorage(test_xml, cv::FileStorage::READ);
		cv::FileStorage yml_fs_assign = cv::FileStorage(test_yml, cv::FileStorage::READ);
		cv::FileStorage json_fs_assign = cv::FileStorage(test_json, cv::FileStorage::READ);

		// See if the assigned cv::FileStorage objects are opened
		{
			assert(xml_fs_assign.isOpened());
			/*if (xml_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for XML file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for XML file did not open" << std::endl;
				return -1;
			}*/

			assert(yml_fs_assign.isOpened());
			/*if (yml_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for YAML file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for YAML file did not open" << std::endl;
				return -1;
			}*/

			assert(json_fs_assign.isOpened());
			/*if (json_fs_assign.isOpened())
			{
				std::cout << "Assigned cv::FileStorage object for JSON file is open" << std::endl;
			}
			else
			{
				std::cout << "Assigned cv::FileStorage object for JSON file did not open" << std::endl;
				return -1;
			}*/
		}

		// See if at least the 2D matrix in the cv::FileStorage objects can be read
		// and if they are the same
		{
			cv::Mat assigned_xml_2d_mat;
			cv::Mat assigned_yml_2d_mat;
			cv::Mat assigned_json_2d_mat;
			bool eq = false;

			xml_fs_assign["normal_2d_mat"] >> assigned_xml_2d_mat;
			yml_fs_assign["normal_2d_mat"] >> assigned_yml_2d_mat;
			json_fs_assign["normal_2d_mat"] >> assigned_json_2d_mat;

			// Does the XML copy have the same matrix as the original?
			eq = (cv::sum(xml_2d_mat != assigned_xml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied XML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied XML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the YAML copy have the same matrix as the original?
			eq = (cv::sum(yml_2d_mat != assigned_yml_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied YAML FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied YAML FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/

			// Does the JSON copy have the same matrix as the original?
			eq = (cv::sum(json_2d_mat != assigned_json_2d_mat) == cv::Scalar(0, 0, 0, 0));
			assert(eq);
			/*if (eq)
			{
				std::cout << "The copied JSON FileStorage object returns the same 2D Matrix as the original" << std::endl;
			}
			else
			{
				std::cout << "The copied JSON FileStorage object did not return the same 2D Matrix as the original" << std::endl;
				return -1;
			}*/
		}
	}
	std::cout << std::endl;

	
	// We are going to close the original files as we are now
	// going to test corner cases
	org_xml_fs.release();
	org_yml_fs.release();
	org_json_fs.release();

	std::cout << "##### Testing Corner Cases #####" << std::endl;
	{
		// 1. Initialize xml_fs
		// 2. Initialize test_fs using copy constructor and xml_fs.
		// 3. Close the file being handled by xml_fs
		// 4. Test to see the file handled by test_fs is closed (it shouldn't be as copy constructor provides deep copies)
		{
			cv::FileStorage xml_fs(test_xml, cv::FileStorage::READ);
			cv::FileStorage test_fs(xml_fs);

			// Close original file
			xml_fs.release();

			assert(test_fs.isOpened());
			/*if (test_fs.isOpened())
			{
				std::cout << "Passed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage using copy constructor, " << std::endl
						  << "which was later closed." << std::endl;
			}
			else
			{
				std::cout << "Failed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage using copy constructor, " << std::endl
						  << "which was later closed." << std::endl;
				return -1;
			}*/
		}

		// Initializing a cv::FileStorage object with another using assignment operator,
		// then closing the file that the other opened. If deep copy works, the
		// initalized file storage object should still access file

		// 1. Initialize xml_fs
		// 2. Initialize test_fs using assignment operator and xml_fs.
		// 3. Close the file being handled by xml_fs
		// 4. Test to see the file handled by test_fs is closed (it shouldn't be as assignment operator provides deep copies)
		{
			cv::FileStorage xml_fs(test_xml, cv::FileStorage::READ);
			cv::FileStorage test_fs = xml_fs;

			// Close original file
			xml_fs.release();

			assert(test_fs.isOpened());
			/*if (test_fs.isOpened())
			{
				std::cout << "Passed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage using assignment operator, " << std::endl
						  << "which was later closed." << std::endl;
			}
			else
			{
				std::cout << "Failed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage using assignment operator, " << std::endl
						  << "which was later closed." << std::endl;
				return -1;
			}*/
		}


		// 1. Initialize xml_fs
		// 2. Close file handled by xml_fs
		// 3. Initalized test_fs with xml_fs using copy constructor
		// 4. Test to see if the file handled by test_fs is closed (it should be as copy constructor provides deep copies and xml_fs is closed)
		{
			cv::FileStorage xml_fs(test_xml, cv::FileStorage::READ);
			// Close file
			xml_fs.release();

			cv::FileStorage test_fs(xml_fs);

			assert(!test_fs.isOpened());
			/*if (!test_fs.isOpened())
			{
				std::cout << "Passed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage that had its file closed " << std::endl 
						  << "using copy constructor." << std::endl;
			}
			else
			{
				std::cout << "Failed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage that had its file closed " << std::endl
						  << "using copy constructor. The initialized cv::FileStorage" << std::endl
						  << "should not be opened." << std::endl;
				return -1;
			}*/
		}

		// 1. Initialize xml_fs
		// 2. Close file handled by xml_fs
		// 3. Initalized test_fs with xml_fs using assignment operator
		// 4. Test to see if the file handled by test_fs is closed (it should be as assignment operator provides deep copies and xml_fs is closed)
		{
			cv::FileStorage xml_fs(test_xml, cv::FileStorage::READ);
			// Close file
			xml_fs.release();

			cv::FileStorage test_fs = xml_fs;

			assert(!test_fs.isOpened());
			/*if (!test_fs.isOpened())
			{
				std::cout << "Passed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage that had its file closed " << std::endl
						  << "using assignment operator." << std::endl;
			}
			else
			{
				std::cout << "Failed case where cv::FileStorage object is initialized" << std::endl
						  << "with another cv::FileStorage that had its file closed " << std::endl
						  << "using assignment operator. The initialized cv::FileStorage" << std::endl
						  << "should not be opened." << std::endl;
				return -1;
			}*/
		}
	}
	std::cout << std::endl;

	return 0;
}