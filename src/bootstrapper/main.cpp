// clang-format off
#include <atlbase.h>
// clang-format off
#include <atlapp.h>
#include <atlmisc.h>

CAppModule _Module;

class CMainWindow final : public CWindowImpl<CMainWindow, CWindow, CFrameWinTraits> {
private:
    // clang-format off
    BEGIN_MSG_MAP(CMainWindow)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_MOVE, OnMove)
    END_MSG_MAP()
    // clang-format on

private:
    LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
        CPaintDC dc{ *this };
        CRect rect;
        GetClientRect(rect);
        dc.DrawText(L"This is bootstrapper.", -1, rect,
                    DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        return 0;
    }

    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
        PostQuitMessage(0);
        return 0;
    }

    LRESULT OnMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
        const auto point = MAKEPOINTS(lParam);
        CString str;
        str.Format(_T("%d : %d"), point.x, point.y);
        SetWindowText(str);
        return 0;
    }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    _Module.Init(nullptr, hInstance, nullptr);

    CMainWindow window;
    window.Create(nullptr, CWindow::rcDefault, L"bootstrapper");
    window.ShowWindow(SW_SHOW);

    CMessageLoop loop;
    const auto res = loop.Run();

    _Module.Term();

    return res;
}
