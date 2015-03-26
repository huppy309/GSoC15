#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("TestExample");

int
main (int argc, char *argv[])
{
  NodeContainer nodes;
  nodes.Create (1);

  Ptr<TestApplication> test = CreateObject<TestApplication>();
  Ptr<Node> node = nodes.Get(0);
  node -> AddApplication(test); 
  test -> SetStartTime(Seconds(1));
  test -> SetStopTime(Seconds(2));

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
